#include "wave.h"

struct WAVData* audioread(const char* filename) {
    // 打开文件
    FILE* inputFile = fopen(filename, "rb");
    struct WAVData* audio_data = NULL;
    if (inputFile == NULL) {
        perror("文件打开失败!");
        return NULL;
    }

    // 读取文件头部信息
    struct WAVHeader header;
    fread(&header, sizeof(struct WAVHeader), 1, inputFile);

    // 验证文件格式
    if (strncmp(header.chunkID, "RIFF", 4) != 0 || strncmp(header.format, "WAVE", 4) != 0) {
        perror("无效文件!");
        fclose(inputFile);
        return NULL;
    }

    // 输出wav文件信息
    printf("音频格式: %hu\n", header.audioFormat);
    printf("声道数: %hu\n", header.numChannels);
    printf("采样率: %hu\n", header.sampleRate);
    printf("采样深度: %hu\n", header.bitsPerSample);
    printf("数据大小: %u\n", header.subchunk2Size);

    // 读取wav文件数据
    audio_data = (struct WAVData*)malloc(sizeof(struct WAVData));
    if (audio_data == NULL) {
        perror("内存申请失败!");
        return NULL;
    }
    audio_data->header = header;
    audio_data->sample = (uint8_t*)malloc(header.subchunk2Size);
    if (audio_data->sample == NULL) {
        perror("内存申请失败!");
        free(audio_data);
        return NULL;
    }
    fread(audio_data->sample, header.subchunk2Size, 1, inputFile);
    fclose(inputFile);

    return audio_data;
}

void audiowrite(const char* filename, struct WAVData* audio_data) {
    // 打开输出文件
    FILE* outputFile = fopen(filename, "wb");
    if (outputFile == NULL) {
        perror("output文件打开失败!");
        return;
    }

    // 写入文件
    fwrite(&audio_data->header, sizeof(struct WAVHeader), 1, outputFile);
    fwrite(audio_data->sample, audio_data->header.subchunk2Size, 1, outputFile);

    // 关闭文件
    fclose(outputFile);
}

int main() {
    char filename[80] = "/Users/wangxiaoyi/Documents/Coding/pcie_dma_host/host_driver/input/test.wav";
    struct WAVData* audio_data = audioread(filename);
    if (audio_data == NULL) {
        perror("文件打开失败!");
        return 1;
    }

    char outfilename[80] = "/Users/wangxiaoyi/Documents/Coding/pcie_dma_host/host_driver/output/test.wav";
    audiowrite(outfilename, audio_data);

    return 0;
}