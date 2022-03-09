#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class Classifier {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        uint8_t votes[3] = { 0 };
                        // tree #1
                        if (x[24] <= 0.2149999961256981) {
                            if (x[13] <= 0.4701938182115555) {
                                votes[1] += 1;
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        else {
                            if (x[34] <= 0.06499999947845936) {
                                if (x[11] <= 0.9350000023841858) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[5] <= 0.2735011726617813) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[35] <= 0.1550000011920929) {
                                            if (x[9] <= -0.32500000298023224) {
                                                if (x[43] <= 0.03499999921768904) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }

                                            else {
                                                if (x[29] <= 0.024671963416039944) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    if (x[20] <= 8.207404136657715) {
                                                        votes[0] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[26] <= 0.23499999940395355) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        // tree #2
                        if (x[27] <= 0.33500000834465027) {
                            if (x[40] <= -0.044999999925494194) {
                                if (x[33] <= -0.014999999664723873) {
                                    if (x[47] <= 20.0) {
                                        if (x[28] <= 0.26605768501758575) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }

                                    else {
                                        if (x[21] <= 0.40501318871974945) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[29] <= 0.02886943705379963) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[47] <= 23.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[45] <= 0.02294539101421833) {
                                    if (x[18] <= 7.659999847412109) {
                                        if (x[43] <= 0.03499999921768904) {
                                            if (x[30] <= 29.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[1] <= 6.674999952316284) {
                                                    if (x[11] <= 1.39000004529953) {
                                                        votes[0] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }

                                                else {
                                                    votes[0] += 1;
                                                }
                                            }
                                        }

                                        else {
                                            if (x[32] <= -0.1249999962747097) {
                                                if (x[46] <= 27.5) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        else {
                            if (x[36] <= -0.11038461700081825) {
                                if (x[11] <= 1.64000004529953) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[2] += 1;
                                }
                            }

                            else {
                                if (x[8] <= -1.3100000023841858) {
                                    if (x[13] <= 0.3761163800954819) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    if (x[11] <= 1.1949999928474426) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[12] <= -0.5691346228122711) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        // tree #3
                        if (x[13] <= 0.47207240760326385) {
                            if (x[42] <= 0.014999999664723873) {
                                if (x[28] <= 0.2778846174478531) {
                                    if (x[12] <= -0.4397115409374237) {
                                        if (x[45] <= 0.03289748169481754) {
                                            if (x[11] <= 1.534999966621399) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[21] <= 0.33417901396751404) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[0] += 1;
                                                }
                                            }
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    if (x[20] <= 7.86144232749939) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[20] <= 7.872499942779541) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[45] <= 0.02557373046875) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[2] += 1;
                                }
                            }
                        }

                        // tree #4
                        if (x[27] <= 0.33500000834465027) {
                            if (x[43] <= 0.03499999921768904) {
                                if (x[5] <= 0.2829204946756363) {
                                    if (x[0] <= 5.384999990463257) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[21] <= 0.24117233604192734) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                if (x[24] <= 0.20499999821186066) {
                                    if (x[32] <= -0.1249999962747097) {
                                        if (x[18] <= 7.5) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    if (x[40] <= -0.06499999947845936) {
                                        if (x[46] <= 24.0) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }

                                    else {
                                        if (x[39] <= 32.5) {
                                            if (x[47] <= 29.5) {
                                                if (x[2] <= 4.974999904632568) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }

                                            else {
                                                if (x[0] <= 5.159999847412109) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        else {
                            if (x[13] <= 0.4171504080295563) {
                                votes[1] += 1;
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        // tree #5
                        if (x[13] <= 0.47207240760326385) {
                            if (x[8] <= -1.215000033378601) {
                                if (x[41] <= 0.044999999925494194) {
                                    if (x[40] <= -0.03499999921768904) {
                                        if (x[0] <= 5.369999885559082) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        if (x[30] <= 29.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[28] <= 0.2782692313194275) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[2] <= 5.5299999713897705) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[20] <= 8.163172721862793) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[3] <= 6.525000095367432) {
                                        if (x[18] <= 7.504999876022339) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[37] <= 0.016663829796016216) {
                                                if (x[3] <= 6.434999942779541) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[0] += 1;
                                                }
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[22] <= 25.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[43] <= 0.0950000025331974) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        else {
                            votes[2] += 1;
                        }

                        // tree #6
                        if (x[13] <= 0.4701938182115555) {
                            if (x[43] <= 0.044999999925494194) {
                                if (x[12] <= -0.4344230741262436) {
                                    if (x[12] <= -0.9584615528583527) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[39] <= 29.5) {
                                    if (x[45] <= 0.02661899570375681) {
                                        if (x[0] <= 5.235000133514404) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    if (x[37] <= 0.020529216155409813) {
                                        if (x[45] <= 0.024336135014891624) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            votes[2] += 1;
                        }

                        // tree #7
                        if (x[26] <= 0.2149999961256981) {
                            if (x[11] <= 1.5649999976158142) {
                                if (x[19] <= 9.010000228881836) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[2] += 1;
                                }
                            }

                            else {
                                if (x[41] <= 0.0) {
                                    if (x[13] <= 0.5154376178979874) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    votes[2] += 1;
                                }
                            }
                        }

                        else {
                            if (x[42] <= 0.014999999664723873) {
                                if (x[36] <= -0.09153846278786659) {
                                    if (x[27] <= 0.4749999940395355) {
                                        if (x[41] <= 0.024999999441206455) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    if (x[12] <= -0.9531730711460114) {
                                        if (x[32] <= -0.11499999836087227) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }

                                    else {
                                        if (x[3] <= 6.2799999713897705) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[4] <= 5.7415385246276855) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #8
                        if (x[11] <= 1.7000000476837158) {
                            if (x[43] <= 0.044999999925494194) {
                                if (x[44] <= 0.0010576923086773604) {
                                    if (x[18] <= 7.764999866485596) {
                                        if (x[43] <= 0.03499999921768904) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[0] <= 5.294999837875366) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    if (x[3] <= 6.520000219345093) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[1] <= 6.580000162124634) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[21] <= 0.40501318871974945) {
                                    if (x[12] <= -0.41788461804389954) {
                                        if (x[13] <= 0.4701938182115555) {
                                            if (x[16] <= 7.170000076293945) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    if (x[42] <= 0.08500000089406967) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[16] <= 6.930000066757202) {
                                if (x[15] <= 23.0) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[2] += 1;
                                }
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        // tree #9
                        if (x[8] <= -1.7000000476837158) {
                            if (x[10] <= 0.29499999433755875) {
                                votes[2] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        else {
                            if (x[36] <= -0.09134615212678909) {
                                if (x[9] <= 0.17000000178813934) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[2] += 1;
                                }
                            }

                            else {
                                if (x[40] <= -0.0950000025331974) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[27] <= 0.3400000035762787) {
                                        if (x[12] <= -0.4386538416147232) {
                                            if (x[5] <= 0.2823695242404938) {
                                                if (x[12] <= -0.9514423310756683) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[0] += 1;
                                                }
                                            }

                                            else {
                                                if (x[10] <= 0.32500000298023224) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    if (x[43] <= 0.03499999921768904) {
                                                        votes[0] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }
                            }
                        }

                        // tree #10
                        if (x[25] <= 0.33500000834465027) {
                            if (x[40] <= -0.03499999921768904) {
                                if (x[34] <= 0.024999999441206455) {
                                    votes[2] += 1;
                                }

                                else {
                                    if (x[32] <= -0.13499999791383743) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[45] <= 0.01898074336349964) {
                                            if (x[0] <= 5.299999952316284) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            if (x[46] <= 28.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[20] <= 8.210192203521729) {
                                                    if (x[8] <= -1.1100000143051147) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        votes[0] += 1;
                                                    }
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[20] <= 8.21173095703125) {
                                    if (x[43] <= 0.04499999899417162) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        else {
                            if (x[13] <= 0.41919080913066864) {
                                votes[1] += 1;
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        // return argmax of votes
                        uint8_t classIdx = 0;
                        float maxVotes = votes[0];

                        for (uint8_t i = 1; i < 3; i++) {
                            if (votes[i] > maxVotes) {
                                classIdx = i;
                                maxVotes = votes[i];
                            }
                        }

                        return classIdx;
                    }

                    /**
                    * Predict readable class name
                    */
                    const char* predictLabel(float *x) {
                        return idxToLabel(predict(x));
                    }

                    /**
                    * Convert class idx to readable name
                    */
                    const char* idxToLabel(uint8_t classIdx) {
                        switch (classIdx) {
                            case 0:
                            return "idle";
                            case 1:
                            return "mov";
                            case 2:
                            return "anom";
                            default:
                            return "Houston we have a problem";
                        }
                    }

                protected:
                };
            }
        }
    }