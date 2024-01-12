/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_HARDWARE_RENDERSCRIPT_V1_0_DEVICE_H
#define ANDROID_HARDWARE_RENDERSCRIPT_V1_0_DEVICE_H

#include "cpp/rsDispatch.h"
#include "dlfcn.h"
#include <android/hardware/renderscript/1.0/IDevice.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace android {
namespace hardware {
namespace renderscript {
namespace V1_0 {
namespace implementation {

using ::android::hardware::renderscript::V1_0::ContextType;
using ::android::hardware::renderscript::V1_0::IContext;
using ::android::hardware::renderscript::V1_0::IDevice;
using ::android::hidl::base::V1_0::IBase;
using ::android::hardware::Return;
using ::android::sp;

struct Device : public IDevice {
    Device();
    static dispatchTable& getHal();

    // Methods from ::android::hardware::renderscript::V1_0::IDevice follow.
    Return<sp<IContext>> contextCreate(uint32_t sdkVersion, ContextType ct, int32_t flags) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.

 private:
    static dispatchTable mDispatchHal;
};

extern "C" IDevice* HIDL_FETCH_IDevice(const char* name);

}  // namespace implementation
}  // namespace V1_0
}  // namespace renderscript
}  // namespace hardware
}  // namespace android

#endif  // ANDROID_HARDWARE_RENDERSCRIPT_V1_0_DEVICE_H
