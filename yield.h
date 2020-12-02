//
// Created by Louk Smalbil on 02/12/2020.
//

#ifndef CTEST_YIELD_H
#define CTEST_YIELD_H
#include <stdbool.h>
#include <math.h>

int yield_to_maturity (float sensitivity) {
    int bond_price = 0;
    float YTM_pos = 0.0001;
    float YTM_neg = -0.0001;
    float market_price = 0;
    float coupon_value = 10;
    float face_value = 12;
    int n = 2;

    float lower_bound = market_price - (market_price * sensitivity);
    float upper_bound = market_price + (market_price * sensitivity);

    while (lower_bound < bond_price < upper_bound) {
        if (face_value > market_price) {
            bond_price = (coupon_value * ((1 - (1 / (pow((1 + YTM_pos), n)))) / YTM_pos)) + (
                    face_value * (1 / (pow((1 + YTM_pos), n))));

            YTM_pos += 0.0001;

        } else {
            /*  double check this  */
            bond_price = (coupon_value * ((1 - (1 / (pow((1 + YTM_neg), n))) / YTM_neg)) + (
                    face_value * (1 / (pow((1 + YTM_neg), n)))));

            YTM_neg -= 0.0001;
        }
    }

    if (YTM_pos == 0.0001) {
        return YTM_neg;
    } else {
        return YTM_pos;
    }


}

#endif //CTEST_YIELD_H
