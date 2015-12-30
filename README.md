delorean
==============
In-memory read preference time series database written in C++.


###

Install steps:

1. Clone and cd into repository

2. Build project

        cmake CMakeLists.txt
        make

3. Run tests

        ./test/delorean/runDeloreanTests

4. Run delorean

        ./delorean_run


###

Available commands:

1. CREATE \<id\> \<timestamp\> \<data\> - create bucket for an \<id\>

        CREATE 1 1 1.0
        OK 1 1.0

2. UPDATE \<id\> \<timestamp\> \<data\> - update bucket to add or modify data

        UPDATE 1 5 1.5
        OK 5 1.5
        UPDATE 1 4 1.4
        OK 4 1.4

2. GET \<id\> \<timestamp\> - get latest data for given \<timestamp\>

        GET 1 2
        OK 1 1.0

2. LATEST \<id\> - get latest data for bucket

        LATEST 1
        OK 5 1.5

2. DELETE \<id\> \<timestamp\> - delete data newer than \<timestamp\>

        DELETE 1 4
        OK 4 1.4
        LATEST 1
        OK 4 1.4
