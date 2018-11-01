LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
       AudioTrackDemo.cpp \

LOCAL_SHARED_LIBRARIES := \
        libmedia \
        liblog \
        libaudioclient \
        libutils 


#LOCAL_C_INCLUDES := 

LOCAL_MODULE:= audiotrackdemo

include $(BUILD_EXECUTABLE)

