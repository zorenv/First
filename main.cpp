#include "Hash.h"

int main()
{
    if( !(fp = fopen("Hash.txt", "r")) )
    {
        printf("Open file failed!\n");
        exit(1);
    }

    InputNumber();

    ShowNumber();

    makeHashList();

    Result();

    fclose(fp);
    return 0;
}
