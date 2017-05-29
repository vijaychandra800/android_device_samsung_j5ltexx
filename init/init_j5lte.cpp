/*
   Copyright (c) 2016, The Linux Foundation. All rights reserved.
   Copyright (c) 2017, The LineageOS Project. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void init_dsds() {
    property_set("ro.multisim.set_audio_params", "true");
    property_set("ro.multisim.simslotcount", "2");
    property_set("persist.radio.multisim.config", "dsds");
}

void init_single() {
    property_set("ro.multisim.set_audio_params", "true");
    property_set("ro.multisim.simslotcount", "1");
    property_set("persist.radio.multisim.config", "none");
}

void vendor_load_properties()
{
    std::string platform = property_get("ro.board.platform");
    if (platform != ANDROID_TARGET)
        return;

    std::string bootloader = property_get("ro.bootloader");

    if (bootloader.find("J500FN") == 0) {
        /* SM-J500FN */
        property_set("ro.build.fingerprint", "samsung/j5nltexx/j5nlte:7.1.2/MMB29M/J500FNXXU1BPK3:user/release-keys");
        property_set("ro.build.description", "j5nltexx-user 7.1.2 MMB29M J500FNXXU1BPK3 release-keys");
        property_set("ro.product.model", "SM-J500FN");
        property_set("ro.product.device", "j5nlte");
        init_single();
    } else if (bootloader.find("J500Y") == 0) {
        /* SM-J500Y */
        property_set("ro.build.fingerprint", "samsung/j5nltexx/j5nlte:7.1.2/MMB29M/J500FNXXU1BPK3:user/release-keys");
        property_set("ro.build.description", "j5nltexx-user 7.1.2 MMB29M J500FNXXU1BPK3 release-keys");
        property_set("ro.product.model", "SM-J500Y");
        property_set("ro.product.device", "j5yltedo");
        init_single();
    } else if (bootloader.find("J500F") == 0) {
        /* SM-J500Y */
        property_set("ro.build.fingerprint", "samsung/j5nltexx/j5nlte:7.1.2/MMB29M/J500FNXXU1BPK3:user/release-keys");
        property_set("ro.build.description", "j5nltexx-user 7.1.2 MMB29M J500FNXXU1BPK3 release-keys");
        property_set("ro.product.model", "SM-J500F");
        property_set("ro.product.device", "j5lte");
        init_dsds();
    } else if (bootloader.find("J500G") == 0) {
        /* SM-J500Y */
        property_set("ro.build.fingerprint", "samsung/j5nltexx/j5nlte:7.1.2/MMB29M/J500FNXXU1BPK3:user/release-keys");
        property_set("ro.build.description", "j5nltexx-user 7.1.2 MMB29M J500FNXXU1BPK3 release-keys");
        property_set("ro.product.model", "SM-J500G");
        property_set("ro.product.device", "j5lteub");
        init_dsds();
    } else if (bootloader.find("J500M") == 0) {
        /* SM-J500Y */
        property_set("ro.build.fingerprint", "samsung/j5nltexx/j5nlte:7.1.2/MMB29M/J500FNXXU1BPK3:user/release-keys");
        property_set("ro.build.description", "j5nltexx-user 7.1.2 MMB29M J500FNXXU1BPK3 release-keys");
        property_set("ro.product.model", "SM-J500M");
        property_set("ro.product.device", "j5ltedx");
        init_dsds();
    }

    std::string device = property_get("ro.product.device");
    INFO("Found bootloader id %s setting build properties for %s device\n", bootloader.c_str(), device.c_str());
}
