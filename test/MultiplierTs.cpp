#include <gtest/gtest.h>
#include <Multiplier.h>

class MultiplierTs : public ::testing::Test,
                     public ::testing::WithParamInterface<std::tuple<int, int>> {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(MultiplierTs, GIVEN_any_number_and_a_zero_WHEN_multiply_THEN_results_zero) {
    ASSERT_EQ(multiply(5, 0), 0);
}

TEST_F(MultiplierTs, GIVEN_a_5_and_a_10_WHEN_multiply_THEN_50_is_returned) {
    ASSERT_EQ(multiply(5, 10), 50);
}

TEST_F(MultiplierTs, GIVEN_a_5_and_a_minus_10_WHEN_multiply_THEN_minus_50_is_returned) {
    ASSERT_EQ(multiply(5, -10), -50);
}

TEST_F(MultiplierTs, GIVEN_a_minus_5_and_a_minus_10_WHEN_multiply_THEN_50_is_returned) {
    ASSERT_EQ(multiply(-5, -10), 50);
}

TEST_F(MultiplierTs, GIVEN_two_really_big_numbers_WHEN_multiply_THEN_right_result_is_returned) {
    ASSERT_EQ(multiply(10000, 10000), 10000*10000);
}

TEST_P(MultiplierTs, GIVEN_two_numbers_WHEN_multiply_in_different_order_THEN_same_result_is_returned) {
    EXPECT_EQ(multiply(std::get<0>(GetParam()), std::get<1>(GetParam())),
              multiply(std::get<1>(GetParam()), std::get<0>(GetParam())));
}

INSTANTIATE_TEST_SUITE_P(positive_negative_zero_combinations,
                         MultiplierTs,
                         testing::Values(std::make_tuple(5, 10),
                                         std::make_tuple(5, -10),
                                         std::make_tuple(-5, -10),
                                         std::make_tuple(5, 0),
                                         std::make_tuple(0, 0)));