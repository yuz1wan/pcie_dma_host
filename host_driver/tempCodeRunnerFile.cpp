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