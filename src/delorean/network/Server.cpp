//
// Created by sebastian on 06/02/16.
//

#include "Server.h"
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <sstream>
#include <thread>
#include <query/ClientQuery.h>

void handleClient(int clientSock, TemporalDatastore *temporalDatastore) {
    char buffer[256];
    ClientQuery clientQuery;

    while(true) {
        bzero(buffer, 256);
        int n = read(clientSock, buffer, 255);

        if(n < 0){
            std::cerr << "ERROR reading from socket. rc=" << n << std::endl;
            break;
        }
        else {
            std::string input(buffer);
            std::string result = clientQuery.executeQuery(input, temporalDatastore);

            n = write(clientSock, result.c_str(), result.size());

            if (n < 0) {
                std::cerr << "ERROR writing to socket. rc=" << n << std::endl;
                break;
            }
        }
    }

    std::cout << "Closing socket " << clientSock << std::endl;

    close(clientSock);
}

void Server::start(TemporalDatastore *temporalDatastore) {
    int sockfd;
    int portno = 3000;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        std::cerr << "Socket connection failed. rc=" << sockfd << std::endl;
        return;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if(bind(sockfd, (struct sockaddr* ) &serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "ERROR on binding" << std::endl;
        return;
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    std::vector<std::thread> workers;

    while(true) {
        int clientSock = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

        if(clientSock < 0) {
            std::cerr << "ERROR on accept. rc=" << clientSock << std::endl;
            break;
        }

        auto t = std::thread(&handleClient, clientSock, temporalDatastore);
        workers.push_back(std::move(t));

        std::vector<std::thread>::iterator threadIterator = workers.end();
        while(threadIterator != workers.end()) {
            if(threadIterator->joinable()) {
                threadIterator->join();
                workers.erase(threadIterator);
            }

            threadIterator++;
        }
    }

    close(sockfd);
}
