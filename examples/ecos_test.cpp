// VolEsti

// Copyright (c) 2012-2017 Vissarion Fisikopoulos

// VolEsti is free software: you can redistribute it and/or modify it
// under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at
// your option) any later version.
//
// VolEsti is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// for more details.
//
// See the file COPYING.LESSER for the text of the GNU Lesser General
// Public License.  If you did not receive this file along with HeaDDaCHe,
// see <http://www.gnu.org/licenses/>.
#include "../external/ecos/ECOS/include/ecos.h"
#include <iostream>
//#include "ECOS/include/ecos_bb.h"

int main(const int argc, const char** argv)
{
    idxint n = 2;
    idxint m = 2;
    pfloat feas_Gx[4] = {2.0, 3.0, 1.0, 4.0};
    idxint feas_Gp[3] = {0, 2, 4};
    idxint feas_Gi[4] = {0, 1, 0, 1};

    pfloat feas_c[2] = {-1.1, -1.};
    pfloat feas_h[2] = {4., 12.};

    idxint bool_idx[1] = {0};

    /* Answer: */
    pfloat x[2] = {1.0, 2.0};

    idxint i, ret_code, pass;


    pwork* prob = ECOS_setup(n, m, 0,
                             m, 0, NULL, 0,
                             feas_Gx, feas_Gp, feas_Gi,
                             NULL, NULL, NULL,
                             feas_c, feas_h, NULL);

    prob->stgs->verbose = 2;

    ret_code = ECOS_solve(prob);

    ECOS_cleanup(prob, 0);

    std::cout << "Passed\n";
    std::cout << ret_code << std::endl;


    return 0;
}
