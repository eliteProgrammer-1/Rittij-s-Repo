#include<stdio.h>

struct phone
{
    int screenLength, memory, storage;
    float cameraPixels;
    char *name;
};


int main()
{
    struct phone iPhone12, iPhone13, galaxy;
    iPhone12.cameraPixels = 12;
    iPhone12.memory = 8;
    iPhone12.storage = 32;
    iPhone12.name = "iPhone12";
    iPhone12.screenLength = 6;

    int arr[3] = {1, 1, 3};
    int i = 0;
    // while (iPhone12.name[i] != '\0')
    // {
    //     printf("%c", iPhone12.name[i]);
    //     i++;
    // }
    
    
    
}