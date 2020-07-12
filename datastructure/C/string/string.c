#include <stdio.h>

void string_len(char string[])
{
    int i = 0;
    while(string[i] != '\0'){
        i++;
    }
    printf("%d\n",i);
}
void change_case(char* string)
{
    int i;
    for(i = 0; string[i] != '\0'; i++){
        if(string[i] >= 65 && string[i] <= 90)
            string[i] += 32;
        else if(string[i]>='a' && string[i]<='z')
            string[i] -= 32;
    }
}
void find_vowels(char string[]){
    int i, v_count = 0, c_count = 0;
    for(i = 0; string[i] != '\0'; i++){
        if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' || string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U')
            v_count++;
        else if((string[i] >= 'a' && string[i] <= 'z')||(string[i] >= 'A' && string[i] <= 'Z'))
            c_count++;
    }
    printf("%d vowels & %d constants\n",v_count,c_count);
}
void find_words(char* string)
{
    int i, word = 1;
    for(i = 0; string[i] != '\0'; i++){
        if(string[i] == ' ' && string[i-1] != ' ')
            word++;
    }
    printf("%d words\n",word);
}
void bit_dup(char* string)
{
    int count[26] = {0};
    long int i,x = 0,H = 0;
    for(i = 0; string[i] != '\0'; i++){
        x = 1;
        x = x << (string[i] - 97);
        if((x & H) > 0 && count[string[i] - 97] < 1){
            printf("dup %c\n",string[i]);
            count[string[i] - 97]++;
        }
        else
           H = x | H;
    }
    
}
int main()
{
    char name[] = "yoloooa whats up";
    string_len(name);
    change_case(name);
    change_case(name);
    printf("%s\n",name);
    find_vowels(name);
    find_words(name);
    bit_dup(name);
    return 0;
}