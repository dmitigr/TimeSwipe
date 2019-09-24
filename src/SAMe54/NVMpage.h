/*
This Source Code Form is subject to the terms of the GNU General Public License v3.0.
If a copy of the GPL was not distributed with this
file, You can obtain one at https://www.gnu.org/licenses/gpl-3.0.html
Copyright (c) 2019 Panda Team
*/

#pragma once

struct NVMscpage{

    //16-bit block1:
    uint32_t AC_BIAS            :2;
    uint32_t ADC0_BIASCOMP      :3;
    uint32_t ADC0_BIASREFBUF    :3;
    uint32_t ADC0_BIASR2R       :3;
    uint32_t res1               :5;

    //16-bit block2:
    uint32_t ADC1_BIASCOMP      :3;
    uint32_t ADC1_BIASREFBUF    :3;
    uint32_t ADC1_BIASR2R       :3;
    uint32_t res2               :5;

    //.............................
    //.............................
};