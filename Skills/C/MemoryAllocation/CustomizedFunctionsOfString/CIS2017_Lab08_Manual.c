/*
 * Name:	Xu Jiang 
 * Section:	01 
 * Lab:  	CIS2107_Lab08_Manual 
 * Goal: 	To design and implement functions taking pointers as arguments 
			to process characters and strings.
 */


#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RAND_MIN01 0
#define RAND_MAX01 4

//functions prototypes
void * upperLower(const char * s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr (char * line, char * sub);
int countChar (char * line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[],int size);
void endsWithed(char *string[],int size);

int main() {

    //random generator
    srand(time(NULL));

    //test for upperLower
    const char test[20] = "This iS A Test";    
    upperLower(test);

    //test for convertStrtoInt
    printf("\n\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    //test for convertStrtoFloat
    printf("\n\nThe sum of 4 strings is: %.2f", convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));

    //test for compareStr
    compareStr("Test1", "Test2");

    //test for comparePartialStr
    comparePartialStr("Test1", "Test2", 4);

    //test for randomize
    randomize();

    //test for tokenize number
    char str[20] = "(267) 436-6281";
    tokenizeTelNum(str);

    //test for reverse
    char line[20] = "Hello world";
    reverse(line);

    //test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    //test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n", w, line1, countChar(line1, w));

    //test for countAlpha
    char str1[20] = "Hello it's me.";
    countAlpha(str1);

    //test for countWords
    char countstring[20] = "hello world!";
    printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

    //test for startsWithB
    char *series[20] = {"bored", "hello", "Brother", "manual", "bothered"};
    startsWithB(series,5);

    //test for endsWithed
    endsWithed(series,5);

}

// 1.(Displaying Strings in Uppercase and Lowercase) 
void * upperLower (const char * s) {
    //declare a new string variable to store the template string
    size_t size = strlen(s);
    char str[(int)size];
    
    //convert the string to all upper case and print it
    for(int i = 0; i < size; i++){
        str[i] = toupper(s[i]);
    }
    str[size] = '\0';
    printf("%s\n",str);
    
    //convert the tsirng to all lower case and print it
    for(int i = 0; i < size; i++){
        str[i] = tolower(s[i]);
    }
    printf("%s\n",str);
}

// 2.(Converting Strings to Integers for Calculations) 
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4) {
    //convert the string to int
    int num1 = atoi(s1);
    int num2 = atoi(s2);
    int num3 = atoi(s3);
    int num4 = atoi(s4);
    return num1+num2+num3+num4;
}

//3.(Converting Strings to Floating Point for Calculations) 
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4) {
    //conver the string to float
    float num1 = atof(s1);
    float num2 = atof(s2);
    float num3 = atof(s3);
    float num4 = atof(s4);
    return num1+num2+num3+num4;
}

//4.(Comparing Strings) 
void compareStr(const char *s1, const char *s2) {
    int flag = strcmp(s1,s2); 
    //print the result according to the return value of strcmp()
    if(flag > 0){
        printf("\n\n%s > %s",s1,s2);
    }else if (flag == 0){
        printf("\n\n%s = %s",s1,s2);
    }else{
        printf("\n\n%s < %s",s1,s2);
    }

}

//5.(Comparing Portions of Strings) 
void comparePartialStr(const char *s1, const char *s2, int n) {
    //copy the two string to the template string variables
    printf("\n\nComparison of first %d chars:",n);
    int size01 = strlen(s1);
    int size02 = strlen(s2);
    char s01[size01],s02[size02];
    strcpy(s01,s1);
    strcpy(s02,s2);

    //put a EOF-'\0' to the (n+1)th position
    s01[n] = '\0';
    s02[n] = '\0';
    
    int flag = strcmp(s01,s02); 
    if(flag > 0){
        printf("%s > %s",s1,s2);
    }else if (flag == 0){
        printf("%s = %s",s1,s2);
    }else{
        printf("%s < %s",s1,s2);
    }

}

//6.(Random Sentences) 
void randomize(void) {
    //initializing the arrays
    int num_sentence_story = 5;
    int random = rand()%(RAND_MAX01+1) + RAND_MIN01;
    char sentences[num_sentence_story][100];
    
    //if I directly delacre array of pointers, there will be segementation error.
    //so I declare an array of string then make a array of pointers points to it.
    char articleArray[][10] = {"the", "a", "one", "some" , "any"};
    char (*article)[10] = articleArray;
    char nounArray[][10] = {"boy", "girl", "dog", "town", "car"};
    char (*noun)[10] = nounArray;
    char verbArray[][10] = {"drove", "jumped", "ran", "walked", "skipped"};
    char (*verb)[10] = verbArray;
    char prepositionArray[][10] = {"to", "from", "over", "under", "on"};
    char (*preposition)[10] = prepositionArray;
    
    for(int i = 0 ; i < num_sentence_story; i++){
        //convert the first word to first-letter capitailized word
        random = rand()%(RAND_MAX01+1) + RAND_MIN01;
        char first[10];
        strcpy(first,article[random]);
        first[0] = (char)toupper(first[0]);
        //because this sentence is empty here, I used strcpy to avoid string data error.
        strcpy(sentences[i],first);
        strcat(sentences[i]," ");
        
        //generate random number from 0-4 and add the word to the sentence
        random = rand()%(RAND_MAX01+1) + RAND_MIN01;
        strcat(sentences[i],noun[random]);
        strcat(sentences[i]," ");
        random = rand()%(RAND_MAX01+1) + RAND_MIN01;
        strcat(sentences[i],verb[random]);
        strcat(sentences[i]," ");
        random = rand()%(RAND_MAX01+1) + RAND_MIN01;
        strcat(sentences[i],preposition[random]);
        strcat(sentences[i]," ");
        random = rand()%(RAND_MAX01+1) + RAND_MIN01;
        strcat(sentences[i],article[random]);
        strcat(sentences[i]," ");
        random = rand()%(RAND_MAX01+1) + RAND_MIN01;
        strcat(sentences[i],noun[random]);
        random = rand()%(RAND_MAX01+1) + RAND_MIN01;
    }
    //print out the story
    printf("%s","\n\nStory:\n\n\t");
    for(int i = 0 ; i< num_sentence_story; i++){        
        printf("%s. ",sentences[i]);
    }
}

//7.(Tokenizing Telephone Numbers) 
int tokenizeTelNum(char *num) {
    //convert the two special character '(' and ')' to '-' for convenience.
    char phone[20];
    strcpy(phone,num);
    phone[0] = '-';
    phone[4] = '-';
    
    char teleNum[20];
    //put the area code into the template
    char *template = strtok(phone,"-");
    //convert it to int
    int areaCode = atoi(template);
    //concatenated the area code into teleNum
    strcpy(teleNum,template);
    //put the seven digit phone number into the template
    template = strtok(NULL,"-");
    strcat(template,strtok(NULL,"-"));
    //convert it to long
    long phone_number = atol(template);
    //concatenated the phone number into telenum
    strcat(teleNum,template);
    
    printf("\n\nAreaCode = %d, PhoneNumber = %ld", areaCode,phone_number);
    printf("\n\nTeleNumber: %s",teleNum);

    return areaCode;
    
  
}

//8.(Displaying a Sentence with Its Words Reversed) 
void reverse(char *text) {
    char strArray[100][strlen(text)];
    char *token = strtok(text," ");
    char str[100];
    int count = 0;
    //put all the tokens as an array of string
    strcpy(strArray[count++],token);
    while( (token = strtok(NULL," ")) != NULL){
        strcpy(strArray[count++],token);
    }
    //convert the array contains tokens to the string str in reversed order
    strcpy(str,strArray[count-1]);
    strcat(str," ");
    for(int i = count-2; i>=0; i--){
        strcat(str,strArray[i]);
        strcat(str," ");    
    }
    
    printf("\n\nReversed:%s",str);
    
}

//9.(Counting the Occurrences of a Substring) 
int countSubstr (char * line, char * sub) {
    int count = 0;
    char *target = NULL;
    
    //if line has at least one sub, increase count and move target to next char after the first sub
    if((target = strstr(line,sub)) != NULL){
        count++;
        target++;
    }else{
        return 0;
    }
    
    //starting from next char after the first occurance of sub
    //if there is another sub after the first sub, increase the count and move target to next char after that sub
    while((target = strstr(target,sub)) != NULL){
        count++;
        target++;
    }
    //loop exits when there is no more sub in line, and return the count
    return count;
  
}

//10.(Counting the Occurrences of a Character) 
int countChar (char *line, char c) {
    int count = 0;
    char *target = NULL;
    
    //if line has at least one char c, increase count and move target to next char after the first c
    if((target = strchr(line,c)) != NULL){
        count++;
        target++;
    }else{
        return 0;
    }
    
    //starting from next char after the last occurance of c
    //if there is another sub after the last sub, increase the count and move target to next char after that c
    while((target = strchr(target,c)) != NULL){
        count++;
        target++;
    }
    //loop exits when there is no more c in line, and return the count
    return count;
  
}


//11.(Counting the Letters of the Alphabet in a String) 
void countAlpha(char *string) {
    char template[strlen(string)];
    strcpy(template,string);
    for(int i = 0 ; i < strlen(string) ; i++){
        template[i] = tolower(template[i]);
    }
    char alphaArray[26] = "abcdefghijklmnopqrstuvwxyz";
    printf("\n\nThe sentence \"%s\" has letters below:",string);
    puts("\n");
    for(int i=0;i < 26; i++){
        printf("\t%c,%c | %d\n",toupper(alphaArray[i]),alphaArray[i],countChar(template,alphaArray[i]));
    }
    
 
}

//12.(Counting the Number of Words in a String) 
int countWords(char *string) {
    int countLine = 0;
    int countWord = 0;
    char strArray[100][strlen(string)];
    char *tokenLine,*tokenWord;
    //if there is no newline or space in string, return 1 - only 1 word in string
    if((tokenLine = strtok(string,"\n"))==NULL && (tokenWord = strtok(string," ")) == NULL){
        return 1;
    }else{
        //if there are multiple lines in string, put lines into string array strArray
        if((tokenLine = strtok(string,"\n")) != NULL){
            strcpy(strArray[countLine++],tokenLine);
            while((tokenLine = strtok(NULL,"\n")) != NULL){
                strcpy(strArray[countLine++],tokenLine);
            }
            //Loop through strArray, count words in every line and return countWord
            for(int i = 0; i < countLine; i++){
                //there must be at least one word no matter of what
                countWord++;
                //if current line has only one word, break/skip the current loop.
                if((tokenWord = strtok(strArray[i]," "))==NULL){
                    break;
                }
                //otherwise count every word in the line
                while((tokenWord = strtok(NULL," ")) != NULL){
                    countWord++;
                }
            }
        }else{
            //if there is only one line, count the word and return countWord
            countWord++;
            while((tokenWord = strtok(NULL," ")) != NULL){
                countWord++;
            }
            return countWord;
        }
    }
    return countWord;       
}

//13.(Strings Starting with "b") 
void startsWithB(char *string[],int size) {
    printf("%s","\n\nThe words starts with 'b' are:\n");
    for(int i= 0; i< size; i++){
        char template[strlen(string[i])];
        strcpy(template,string[i]);
        //if the string starts with 'b' or 'B'
        if(template[0] == 'b' || *template == 'B'){
            //the example in sildes shows that all words printed should be lower case b
            *template = 'b';
            printf("%s ",template);
        }
    }
    puts("");
}

//14.(Strings Ending with "ed") 
void endsWithed(char *string[],int size) {
    char *template;
    printf("%s","\n\nThe words ends with 'ed' are:\n");
    for(int i= 0; i< size; i++){
        template = string[i];
        //if the string ends with "ed"
        if((strcmp(template+strlen(template)-2, "ed")) == 0){
            printf("%s ",template);
        }
    }
    puts("");
}