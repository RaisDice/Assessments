#include <stdio.h>
#include <string.h>


void railFence(char *message, char *cipherText, int length, int A); //prototype
void railFence2(char *message, char *cipherText, int length, int A, int B, int dir);
void decrypt()
int main() {
	int i = 0;
	int z = 0;
	int A = 0;
	int B = 0;
	int func;
	FILE *textPrint;
	textPrint = fopen("C:\\Users\\myself and I\\Desktop\\Tex.txt","w"); //sets to write, change by setting file path to the file u want it outputted to

	FILE *textMenu;
	textMenu = fopen("C:\\Users\\myself and I\\Desktop\\MyFile.txt", "r");   // opens file that contains the inputs, Cange this file path to your input file
	if(textMenu == NULL) {
        perror("fopen()");
        return 1;               //stop file error
	}

    char read[1000];
    char message[300];
    char c;
    int key = 0, mesCheck = 0;
    fscanf(textMenu, "%c", &c);
    while (!feof(textMenu)) {  //scans till end of file

        read[i] = c;
        if (c == 61) {   // checks for = as an indicator as to when to record a value from file
           fscanf(textMenu, "%c", &c); //scans all characters in the
           key++;
           if (key == 1) {
               func = c;
           }
           if (key == 2) {
               A = c - '0';  // converts char to int so it can pass through function
           }
           if (key == 3) {
                B = c - '0';
           }
        }
        else {
            fscanf(textMenu, "%c", &c);
        }

        if (key == 4 && mesCheck == 0) {

            if (c == 126) {   // ends message at ~, so checks if c = ~ so its note added to message
                mesCheck = 1;
                fscanf(textMenu, "%c", &c);  //removes ~ by scanning past without printing
            }
            else {
                message[z] = c;   // message is added to an array
                z++;

            }
        }
        i++;


}
    int length = z;


    char railRoad[1024]; //declares array so it can pass into function

    read[i] = 0;
    message[z] = 0;
    printf("%s\n", read);    //prints the arrays which contains the menu that is filled in via the file
    fprintf(textPrint, "%s\n", read);
    printf("________________________________\n\n");//creates clear gap to indicate was is being output
    fprintf(textPrint, "________________________________\n\n");
    if (func>96 && func < 100){         // determines if choice is valid and uses CASEWHERE to selct the function to be used
        switch(func)
        {
        case 97:
            printf("Classic rail encryption\n\n");
            fprintf(textPrint, "Classic rail encryption\n\n");
            railFence (message,railRoad,length,A);
            break;
        case 98:
            printf("2nd level rail encryption\n");
            fprintf(textPrint, "2nd level rail encryption\n");
            railFence2(message, railRoad, length, A, B, 0);
            break;
        case 99:
            printf("2nd level rail decryption\n");
            fprintf(textPrint, "2nd level rail decryption\n");
            railFence2(message, railRoad, length, A, B, 1);
            break;
        case 100:
            printf("decryption of text\n");
            fprintf(textPrint, "decryption of text\n");
            decrypt()
            break;
        }
    }
    else {
        printf("Function not available\n");
        fprintf(textPrint, "Function not available\n");
    }
    fclose(textPrint);

}

//---------------------------------------------------
    void decrypt() {
        FILE *textPrint;
        textPrint = fopen("C:\\Users\\myself and I\\Desktop\\Tex.txt","a");
        FILE *dictionary;
        dictionary = fopen("C:\\Users\\myself and I\\Desktop\\Output.txt", "r")
        if(textMenu == NULL) {
        perror("fopen()");
        return 1;               //stop file error
	}
    }
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
    void railFence2(char *message, char *cipherText, int length, int A, int B, int dir) {
        FILE *textPrint;
        textPrint = fopen("C:\\Users\\myself and I\\Desktop\\Tex.txt","a"); //sets to write at end of existing file
        int i = 0 ,bot = 5, test = 0, count = 0, y = 0, lol = 0, Bdown = 0;// declaration
        char dash = '-';                               // sets d to ascii for -
        char rail[1000][1000];                //declaration of size for array
        rail[0][0] = dash;        //sets all elements in array to -
        if (dir == 0) {
        while (i != A){
            while (y != length) {
                rail[i][y] = dash;
                y++;
                }
            y = 0;
            i++;
        }

        i = 0;
        int Bup = 0;
        int counter = 1;
        y = 0;
        count = 0;
        int nope = 0;
        if (B == 1){
            railFence (message,cipherText,length,A);
            return;
            }
        while (y !=length){
           rail[count][y] = message[lol];
           if (count != A-1 && Bup != 1 && Bdown != 1){
                count++;
                if (count == A-1) {
                    Bup = 1;
                    }
                }
            else if (Bup != 0 && nope != 1) {
                count--;
                counter++;
                if (counter > B) {
                    count++;
                    count++;
                    if (counter == 2*B-1){
                        Bup = 0;
                        counter = 1;
                        Bdown = 1;

                        }
                    }
                }
            else if (Bdown == 1){
                count--;
                if (count == 0) {
                    Bdown = 0;
                }
            }
            y++;
            lol++;
           }
        y = 0;
        count = 0;
        while (i != A){
            while (y != length) {
                printf("%c", rail[i][y]);
                fprintf(textPrint, "%c", rail[i][y]);
                if (rail[i][y] != dash){
                    cipherText[count] = rail[i][y];
                    count++;
                }
                y++;
            }
            printf("\n");
            fprintf(textPrint, "\n");

            y=0;
            i++;
            }
            printf("\nCipher text: %s\n", cipherText);
            fprintf(textPrint, "\nCipher text: %s\n", cipherText);
        }
//----------------------------------------------------------------------------------------------
// decryption------------
        if (dir == 1){
                while (i != A){
            while (y != length) {
                rail[i][y] = dash;
                y++;
                }
            y = 0;
            i++;
        }

        i = 0;
        int Bup = 0;
        int counter = 1;
        y = 0;
        count = 0;
        int nope = 0;
        if (B == 1){
            railFence (message,cipherText,length,A);
            return;
            }
        while (y !=length){
           rail[count][y] = message[lol];
           if (count != A-1 && Bup != 1 && Bdown != 1){
                count++;
                if (count == A-1) {
                    Bup = 1;
                    }
                }
            else if (Bup != 0 && nope != 1) {
                count--;
                counter++;
                if (counter > B) {
                    count++;
                    count++;
                    if (counter == 2*B-1){
                        Bup = 0;
                        counter = 1;
                        Bdown = 1;

                        }
                    }
                }
            else if (Bdown == 1){
                count--;
                if (count == 0) {
                    Bdown = 0;
                }
            }
            y++;
            lol++;
           }
        y = 0;
        count = 0;
        printf("\n");
        fprintf(textPrint, "\n");
        while (i != A){
            while (y != length) {
                if (rail[i][y] == dash){
                printf("%c", rail[i][y]);
                fprintf(textPrint, "%c", rail[i][y]);
                }
                if(rail[i][y] != dash){
                    cipherText[count] = rail[i][y];
                    count++;
                    rail[i][y] = '1';
                    printf("%c", rail[i][y]);
                    fprintf(textPrint, "%c", rail[i][y]);
                }
                y++;
            }
            printf("\n");
            fprintf(textPrint, "\n");

            y=0;
            i++;
            }
            printf("\nCipher text: %s\n", cipherText);
            fprintf(textPrint, "\nCipher text: %s\n", cipherText);
            printf("\n");
            fprintf(textPrint, "\n");
            count = 0;
            y = 0;
            i = 0;
            char numb = '1';
            while  (i != A){
                while (y != length){
                    if (rail[i][y] == numb){
                        rail[i][y] = cipherText[count];
                        count++;
                    }
                    y++;
                }
                y = 0;
                i++;
            }
            i = 0;
            y = 0;
            while (i != A){
                while (y != length) {
                    printf("%c", rail[i][y]);
                    fprintf(textPrint, "%c", rail[i][y]);
                    y++;

                }
                printf("\n");
                fprintf(textPrint, "\n");
                i++;
                y=0;
            }
            printf("\n");
            fprintf(textPrint, "\n");
            char newmes[1000];
            count = 0;
            i = 0;
            y = 0;
            while (y != length){
                while (i != A) {
                    if (rail[i][y] != dash){
                        newmes[count] = rail[i][y];
                        count++;
                    }
                    i++;
                }
                i = 0;
                y++;
            }
        printf("Decrypted message: %s\n", newmes);
        fprintf(textPrint, "Decrypted message: %s\n", newmes);
    }
}

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
    void railFence(char *message, char *cipherText, int length, int A) {
        FILE *textPrint;
        textPrint = fopen("C:\\Users\\myself and I\\Desktop\\Tex.txt","a"); //sets to write at end of existing file
        int i = 0 ,bot = 5, test = 0, count = 0, y = 0, lol = 0; // declaration

        char d = '-';                               // ascii for -
        char okthen[1000][1000];                //declaration of size for array


        okthen[0][0]= d;        //sets all elements in array to -
        i = 0;
          while (i != A){           //sets up grid as 2D arrays by string length by key A
            while (y != length){
                okthen[i][y] = d;
                y++;
            }
            y = 0;
            i++;
          }
          y = 0;

            for (y = 0; y != length; y++){        //Creates the reooccuring pattern for the rail encrypton
                okthen[count][y] = message[lol];
                if (count == 0) {
                    count = count + 1;
                    bot = 1;
                }
                else if (count == A-1){
                    count = count - 1;
                    bot = 0;
                }
                else if (bot == 0){
                    count = count - 1;
                }
                else if (bot == 1) {
                    count = count + 1;
                }
                lol++;
            }
          //resets for printing 2d array
            printf("%s\n\n", message);  //printing the message to be converted
            fprintf(textPrint, "%s\n\n", message);
            i = 0;
            y = 0;
    while (i != A){
            while (y != length){
                printf("%c", okthen[i][y]);
                fprintf(textPrint, "%c", okthen[i][y]);
                if (okthen[i][y] != 45 && okthen[i][y] < 127 && okthen[i][y]>=32 ) {
                    cipherText[test] = okthen[i][y];
                    test++;
                }
                y++;
            }
            printf("\n");
            fprintf(textPrint, "\n");
            y = 0;
            i++;

    }

    printf("\n\nCipher text: %s\n", cipherText);
    fprintf(textPrint, "\n\nCipher text: %s\n", cipherText);
    }







