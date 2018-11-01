#include <stdio.h>
#include <media/AudioTrack.h>
#include <utils/Log.h>


#define TAG    "Logtest"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__)

using namespace android;

int main(int argc __unused, char **argv __unused)
{

   // create the output AudioTrack
   AudioTrack* audiotrack = new AudioTrack();

   status_t status = audiotrack->set(AUDIO_STREAM_MUSIC,  //TODO parameterize this
	   44100,
	   AUDIO_FORMAT_PCM_8_BIT,
	   audio_channel_out_mask_from_count(1),
	   (size_t) 40*1024,
   		AUDIO_OUTPUT_FLAG_NONE);
	
   if (status == OK) {
	   ALOGE("JetPlayer::init(): Error initializing JET library; AudioTrack error %d", status); 
   } 
	LOGD("new success ,start %d",status);
	status = audiotrack->start();

	LOGD("status %d",status);
    FILE* fp = fopen("/sdcard/16k.pcm","rb");

	LOGD("fp %d",fp);
	long int size = 40*1024; 
    unsigned char * buf = new unsigned char[size];

	LOGD("buf %d",buf);
    int len = -1;

	while(!feof(fp)){
		if(buf!=NULL){
			printf("buf != null  %d",buf);
	}
		
	  memset(buf,0,size);
		
	  len = fread(buf, 1, size, fp);
	  LOGD("buf %d",buf);
	   
	  if (len>0)
       {
           audiotrack->write(buf, len); 
		   LOGD("write %d",len);
       }
		 
	}
    fclose(fp);
	
    if (audiotrack != NULL)
		{
		LOGD("stop ");
        audiotrack->stop();
        audiotrack->flush();
    }
  
  
   return 0;
}
