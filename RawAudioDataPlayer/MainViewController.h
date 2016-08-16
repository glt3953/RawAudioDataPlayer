//
//  MainViewController.h
//  RawAudioDataPlayer
//
//  Created by SamYou on 12-8-18.
//  Copyright (c) 2012年 SamYou. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AudioToolbox/AudioToolbox.h>

#define QUEUE_BUFFER_SIZE 4 //队列缓冲个数
#define EVERY_READ_LENGTH 1000 //每次从文件读取的长度
#define MIN_SIZE_PER_FRAME 2000 //每侦最小数据长度

@interface MainViewController : UIViewController
{
    AudioStreamBasicDescription audioDescription;///音频参数
    AudioQueueRef audioQueue;//音频播放队列
    AudioQueueBufferRef audioQueueBuffers[QUEUE_BUFFER_SIZE];//音频缓存
    NSLock *synlock ;///同步控制
    Byte *pcmDataBuffer;//pcm的读文件数据区
    FILE *file;//pcm源文件
}

static void AudioPlayerAQInputCallback(void *input, AudioQueueRef inQ, AudioQueueBufferRef outQB);

-(void)onbutton1clicked;
-(void)onbutton2clicked;
-(void)initAudio;
-(void)readPCMAndPlay:(AudioQueueRef)outQ buffer:(AudioQueueBufferRef)outQB;
-(void)checkUsedQueueBuffer:(AudioQueueBufferRef) qbuf;

@end
