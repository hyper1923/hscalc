#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

uint64_t do_your_job(const char *fn);
uint64_t do_your_job(const char *fn){
    FILE* fp = fopen(fn,"rb");
    uint64_t total = 0;
    while(!feof(fp)){
        total += (uint64_t)fgetc(fp);
    }
    return total;
} 

int main(int argc, char **argv){
    assert(argc > 0);
    uint64_t _sign = do_your_job(argv[1]);
    printf(
        "File Path: %s | Hex: 0x%x | Dec: %d" \
        ,argv[1] , _sign, _sign
    );
}