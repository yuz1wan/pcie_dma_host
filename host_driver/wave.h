#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

// 定义WAV文件头部结构
struct WAVHeader {
    char chunkID[4];        // 文件标识，通常为"RIFF"
    uint32_t chunkSize;     // 文件大小
    char format[4];         // 文件格式，“WAVE”
    char subchunk1ID[4];    // 子块标识，“fmt”
    uint32_t subchunk1Size; // 子块大小
    uint16_t audioFormat;   // 音频格式，1为PCM格式
    uint16_t numChannels;   // 声道数，1:单声道，2:双声道
    uint32_t sampleRate;    // 采样率
    uint32_t byteRate;      // 每秒的字节数
    uint16_t blockAlign;    // 块对齐
    uint16_t bitsPerSample; // 采样深度
    char subchunk2ID[4];    // 子块标识，“data”
    uint32_t subchunk2Size; // 子块大小
};

// 音频数据结构
struct WAVData {
    struct WAVHeader header;  // 音频头部数据
    uint8_t* sample;          // 音频数据
};

// 读取wav格式文件
struct WAVData* audioread(const char* filename);
// 写入wav格式文件
void audiowrite(const char* filename, struct WAVData* audio_data);