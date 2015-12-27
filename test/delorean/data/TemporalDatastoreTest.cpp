//
// Created by sebastian on 19/12/15.
//
#include <data/TemporalDatastore.h>
#include "gtest/gtest.h"

/*
 * Get should return the observation captured at the timestamp or
 * the one directly before the ts. Or raise exception if there is
 * no applicable observation
 */
TEST(TemporalDatastoreTest, testGet) {
    TemporalDatastore ds = TemporalDatastore();
    ds.create(1, 1, "1.1");
    ds.update(1, 3, "1.3");
    ds.update(1, 2, "1.2");
    ds.update(1, 4, "1.4");

    EXPECT_EQ("1.1", ds.get(1, 1).getData());
    EXPECT_EQ("1.2", ds.get(1, 2).getData());
    EXPECT_EQ("1.4", ds.get(1, 100).getData());

    //ts 0 for bucket 1 doesn't exist
    EXPECT_THROW(ds.get(1, 0), std::invalid_argument);

    //bucket 0 doesn't exist
    EXPECT_THROW(ds.get(0, 0), std::invalid_argument);
}

/*
 * Latest returns the latest price for a given bucket id
 */
TEST(TemporalDatastoreTest, testLatest) {
    TemporalDatastore ds = TemporalDatastore();

    ds.create(1, 1, "1.1");
    EXPECT_EQ("1.1", ds.latest(1).getData());

    ds.update(1, 3, "1.3");
    EXPECT_EQ("1.3", ds.latest(1).getData());

    ds.update(1, 2, "1.2");
    EXPECT_EQ("1.3", ds.latest(1).getData());

    ds.update(1, 4, "1.4");
    EXPECT_EQ("1.4", ds.latest(1).getData());
}

/*
 * Remove deletes all observations more recent than the input timestamp
 * and returns the observation less than or equal to timestamp. Throws
 * an invalid_argument exception if no applicable observation exists
 */
TEST(TemporalDatastoreTest, testRemove) {
    TemporalDatastore ds = TemporalDatastore();

    ds.create(1, 1, "1.1");
    ds.update(1, 2, "1.2");
    ds.update(1, 3, "1.3");
    ds.update(1, 4, "1.4");

    EXPECT_EQ("1.4", ds.latest(1).getData());
    EXPECT_EQ("1.2", ds.remove(1, 2).getData());

    EXPECT_THROW(ds.remove(1, 0), std::invalid_argument);
}
