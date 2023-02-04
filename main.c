#include <stdio.h>
#include <direct.h>
#include "string.h"

int print_text(char text[], FILE* fp)
{
    int u =0, kh=0;
    while(u<1000, text[u]!=0){

        if(text[u]!='\\')
            fprintf(fp,"%c", text[u]);
        else
        {
            u++;
            if(text[u]=='\\')
                fprintf(fp, "%c", '\\');
            else if(text[u]=='n')
                fprintf(fp, "\n");
            else
            {
                kh=1;
                break;
            }
        }
        u++;
    }
    return kh;
}

int get_text(char s[], int i, char text[])
{
    int v = 0, kh =0;

    if(s[i] == '"') {
        i++;
        while(s[i]!=0 && s[i] != '-') {
            text[v] = s[i];
            v++;
            i++;
        }
        v--;
        while (v>=0 && text[v]==' ') {
            text[v] = 0;
            v--;
        }
        if(text[v]!='"')
        {
            kh=1;
            printf("invalid command. \n");
        }
        else
        {
            text[v] = 0;
        }
    }
    else
    {
        while(s[i]!=' '&& s[i]!=0 && s[i] != '"')
        {
            text[v] = s[i];
            v++;
            i++;
        }
        if(s[i] =='"')
        {
            kh = 1;
            printf("invalid command");
        }

        for (int uh = v; uh <v+5 ; ++uh) {
            text[v] = 0;
        }

        while (s[i] ==' ')
            i++;
    }
    return 10 * i + kh;
    printf("%s", text);
}

int get_address(char s[], int i, char address[])
{
    int mark =0;

    int v = 0;

    while (s[i] == ' ')
        i++;

    if(s[i] != '"')
    {
        while (s[i] != ' ' && s[i] != 0) {
            address[v + 38] = s[i];

            i++;
            v++;
        }
    }
    else
    {
        i++;
        while (s[i] !='"' && s[i] !=0)
        {
            if(s[i]!=' ')
            {
                address[v+38] = s[i];
                v++;
            }
            i++;
        }
        if(s[i] !='"') {
            printf("invalid command. \n");
            mark = 1;
        }

        else
            i++;
    }
    for (int uh = v; uh < v+5; ++uh) {
        address[v+38] = 0;
    }

    while (s[i] ==' ')
        i++;

    return 10 * i +mark;

}

int check(char a[], char b[])
{
    int k = 0;
    while(k<20)
    {
        if(a[k] != b[k])
            break;
        else
            k++;
    }
    if(k==20)
        return 1;
    else
        return 0;
}

int check_mode(char a[], char b[])
{
    int u = 0;
    while(u<10)
    {
        if(a[u] != b[u])
            break;
        else
            u++;
    }
    if(u==10)
        return 1;
    else
        return 0;
}

char o_create[20] = "createfile", o_insert[20] = "insertstr" , o_cat[20] = "cat", o_remove[20] = "removestr", o_copy[20] = "copystr", o_cut[20] = "cutstr", o_paste[20] = "pastestr", o_find[20] = "find", o_replace[20] = "replace", o_grep[20] = "grep", o_closingpairs[20] = "auto-indent", o_undo[20] = "undo", o_compare[20] = "compare", o_tree[20] = "tree";

char m_file[10] = "-file", m_str[10] = "-str",m_pos[10] = "-pos", m_size[10] = "-size", m_f[10] ="-f", m_b[10] = "-b",m_str1[10] = "-str1", m_str2[10] = "-str2", m_c[10] = "-c", m_l[10] = "-l", m_at[10] = "-at", m_byword[10] = "-byword", m_all[10] = "-all", m_count[10] = "-count";

char address[120] = "C:/users/erfan/ClionProjects/untitled4", clip[4000], fff[10000];

int main() {

    char s[1000], order[20], mode[10], text[1000];

    FILE * fptr;

    while(1)
    {

        for (int i = 0; i < 1000; ++i) {
            s[i] = 0;
        }
        for (int i = 0; i < 20; ++i) {
            order[i] = 0;
        }
        for (int i = 0; i < 10; ++i) {
            mode[i] = 0;
        }
        for (int i = 38; i < 120; ++i) {
            address[i] = 0;
        }
        for (int i = 0; i < 1000; ++i) {
            text[i] = 0;
        }

        gets(s);

        int i = 0;

        while(s[i] == ' ')
            i++;

        int j = 0;

        while (s[i] != ' ' && i < 1000) {
            order[j] = s[i];
            j++;
            i++;
        }
        j = 0;

        while (s[i] == ' ')
            i++;

        while (s[i] !=' ' && j<10)
        {
            mode[j] = s[i];
            j++;
            i++;
        }
        while (s[i] ==' ')
            i++;

        j = 0;

        if(check(order, o_create))
        {

            if(check_mode(mode, m_file)) {

                int mark = get_address(s,i,address);

                i = mark/10;

                if(s[i] !=0 && mark %10 ==0)
                {
                    printf("invalid address.\n");
                }
                else if(mark%10==0)
                {
                    fptr = fopen(address, "r");
                    if (fptr != NULL){
                        printf("The file already exists. \n");
                        fclose(fptr);
                    }
                    else
                    {
                        fclose(fptr);

                        fptr = fopen(address, "a");
                        fclose(fptr);

                        fptr = fopen(address, "r");
                        if(fptr==NULL)
                        {
                            int marko= 0;
                            char new_address[120] = "C:/users/erfan/ClionProjects/untitled4/root/";

                            for (int w = 40; w < 44; ++w) {
                                if(address[w]!=new_address[w])
                                    marko = 1;
                            }

                            if(marko==1)
                                printf("invalid address. \n");
                            else
                            {
                                int x = 44;


                                while(1) {

                                    while (x < 120 && address[x] != '/' && address[x] != 0) {

                                        new_address[x] = address[x];

                                        x++;
                                    }
                                    if(address[x]=='/')
                                        mkdir(new_address);
                                    else
                                    {
                                        fptr = fopen(new_address, "a");
                                        fclose(fptr);
                                        printf("The file created successfully .\n");
                                        break;
                                    }
                                    new_address[x] = '/';
                                    x++;
                                }
                            }

                        }
                        else
                            printf("The file created successfully. \n");
                        fclose(fptr);
                    }
                }

            }
            else
                printf("invalid command. \n");
        }
        else if(check(order, o_insert)) {
            if (check_mode(mode, m_file)) {
                while (s[i] == ' ')
                    i++;

                int mark = get_address(s, i, address);
                i = mark/10;

                if (mark % 10 == 0) {
                    fptr = fopen(address, "r");

                    if (fptr == NULL)
                        mark = 1;

                    fclose(fptr);

                    if (mark == 1)
                        printf("No such file.\n");
                    else {
                        char mode_2[10];

                        j = 0;
                        while (s[i] != ' ' && j<10) {
                            mode_2[j] = s[i];
                            i++;
                            j++;
                        }
                        for (j; j < 10; ++j)
                            mode_2[j] = 0;

                        j = 0;
                        if (check_mode(mode_2, m_str)) {
                            while (s[i] == ' ')
                                i++;

                            for (int k = 0; k < 10; ++k) {
                                mode_2[k] = 0;
                            }
                            mark = get_text(s, i, text);

                            i = mark/10;

                            if (mark % 10 == 0) {

                                while (s[i] != ' ' && j<10) {
                                    mode_2[j] = s[i];
                                    i++;
                                    j++;
                                }
                                for (j ; j < 10; ++j) {
                                    mode_2[j] = 0;
                                }

                                if (check_mode(mode_2, m_pos)) {
                                    while (s[i] ==' ')
                                        i++;

                                    int d, x=1, line;

                                    line = s[i] - 48;
                                    i++;

                                    while (s[i]!=58) {
                                        line = line * 10 + s[i] - 48;
                                        i++;
                                    }

                                    if(s[i]!=58)
                                    {
                                        printf("invalid command.\n");
                                        mark = 1;
                                    }
                                    else
                                    {
                                        i++;
                                        d = s[i] - 48;
                                        i++;
                                        while (s[i]!=' '&&s[i]!=0)
                                        {
                                            d = d* 10 + s[i] -48;
                                            i++;
                                        }
                                        while (s[i] ==' ')
                                            i++;
                                        if(s[i]!=0)
                                        {
                                            printf("invalid command.\n");
                                            mark = 1;
                                        }
                                    }

                                    if(mark!=1)
                                    {
                                        char matn[1000], new_matn[1000],patn[1000];

                                        fptr = fopen(address, "r");

                                        FILE * fp = fopen("C:/users/erfan/ClionProjects/untitled4/root/r_file_r.txt", "a");

                                        while (x <= line && fgets(matn, 1000, fptr)) {
                                            if(x != line)
                                            {
                                                fprintf(fp, "%s", matn);
                                            }
                                            x++;
                                        }

                                        int marko = 0;

                                        if (x == line+1)
                                        {
                                            if(matn[d-1] == 0 && d!=0) {
                                                printf("line %d doesnt have %d characters. \n", line, d);
                                                marko = 1;
                                            }
                                            else
                                            {
                                                printf("The string was inserted at ordered position successfully!\n");
                                                for (int k = d; k < 1000; ++k) {
                                                    new_matn[k-d] = matn[k];
                                                    matn[k] = 0;
                                                }

                                                fprintf(fp, "%s", matn);

                                                marko = print_text(text, fp);

                                                fprintf(fp, "%s", new_matn);
                                                while (fgets(matn,1000,fptr))
                                                    fprintf(fp, "%s",matn);
                                            }
                                            if(!marko)
                                            {
                                                fclose(fp);
                                                fclose(fptr);

                                                fp = fopen("C:/users/erfan/ClionProjects/untitled4/root/r_file_r.txt", "r");
                                                fptr = fopen(address, "w");

                                                while (fgets(patn, 1000, fp))
                                                    fprintf(fptr, "%s", patn);
                                            }
                                        }
                                        else if(x==line)
                                        {
                                            printf("The string in the order was successfully inserted!\n");

                                            fclose(fptr);
                                            fptr = fopen(address, "a");
                                            if(line!=1)
                                            {
                                                fprintf(fptr, "\n");
                                            }
                                            fprintf(fptr, "%s", text);
                                        }
                                        else {
                                            printf("The file doesnt have %d lines.\n", line);
                                            marko = 1;
                                        }

                                        fclose(fp);
                                        fclose(fptr);
                                        remove("C:/users/erfan/ClionProjects/untitled4/root/r_file_r.txt");
                                    }

                                }
                                else
                                    printf("invalid command.\n");
                            }
                        }
                        else
                            printf("invalid command.\n");
                    }
                }
            }
            else
                printf("invalid command.\n");
        }
        else if(check(order, o_cat))
        {
            if(check_mode(mode, m_file))
            {
                int mark  = get_address(s,i,address);
                i = mark/10;

                if(s[i] !=0 && mark%10 ==0)
                {
                    printf("invalid address.\n");
                }

                else if(mark%10==0)
                {
                    fptr = fopen(address, "r");

                    if(fptr == NULL)
                        printf("The file not exists.\n");
                    else
                    {
                        char matn[100];

                        while(fgets(matn, 100, fptr))
                            printf("%s", matn);
                    }
                    printf("\n");

                    fclose(fptr);
                }
            }
        }
        else if(check(order, o_remove))
        {
            if(check_mode(mode, m_file))
            {
                int mark = get_address(s,i,address);
                i = mark/10;
                if(mark % 10 ==0)
                {
                    while (s[i] !=' ' && j<10)
                    {
                        mode[j] = s[i];
                        j++;
                        i++;
                    }
                    while (j<10)
                    {
                        mode[j] =0;
                        j++;
                    }

                    if(check_mode(mode, m_pos)) {
                        while (s[i] == ' ')
                            i++;

                        int d, x = 1, line, size;

                        line = s[i] - 48;
                        i++;

                        while (s[i] != 58) {
                            line = line * 10 + s[i] - 48;
                            i++;
                        }

                        if (s[i] != 58) {
                            printf("invalid command.\n");
                            mark = 1;
                        } else {
                            i++;
                            d = s[i] - 48;
                            i++;
                            while (s[i] != ' ' && s[i] != 0) {
                                d = d * 10 + s[i] - 48;
                                i++;
                            }
                            while (s[i] == ' ')
                                i++;
                        }
                        if (mark != 1) {
                            char mode_2[10];
                            for (int k = 0; k < 10; ++k) {
                                mode_2[k] = 0;
                            }
                            j = 0;
                            while (s[i] != ' ' && j<10) {
                                mode_2[j] = s[i];
                                i++;
                                j++;
                            }
                            if (check_mode(mode_2, m_size)) {
                                while (s[i] == ' ')
                                    i++;
                            } else {
                                mark = 1;
                                printf("invalid command.\n");
                            }
                        }
                        int go = 0;

                        if (mark != 1) {
                            size = s[i] - 48;
                            i++;
                            while (s[i] != ' ') {
                                size = size * 10 + s[i] - 48;
                                i++;
                            }

                            while (s[i] == ' ')
                                i++;

                            for (int k = 0; k < 10; ++k) {
                                mode[k] = 0;
                            }
                            j = 0;
                            while (s[i] != ' ' && s[i] != 0 && j<10) {
                                mode[j] = s[i];
                                j++;
                                i++;
                            }

                            while (s[i] == ' ')
                                i++;

                            if (s[i] == 0) {

                                if (check_mode(mode, m_b))
                                    go = -1;
                                else if (check_mode(mode, m_f))
                                    go = 1;
                                else
                                    mark = 1;
                            } else
                                mark = 1;
                        }

                        if (mark != 1) {
                            char matn[1000], new_matn[1000], patn[1000];
                            int jam=0;
                            int marko =0;

                            fptr = fopen(address, "r");

                            FILE *fp = fopen("C:/users/erfan/ClionProjects/untitled4/root/r_file_r.txt", "a");

                            if(fptr==NULL) {
                                printf("No such file .\n");
                                marko = 1;
                            }
                            else
                            {
                                while (x <= line && fgets(matn, 1000, fptr)) {
                                    if (x != line) {
                                        fprintf(fp, "%s", matn);
                                        j = 0;
                                        while (matn[j]!=0)
                                        {
                                            jam++;
                                            j++;
                                        }
                                    }
                                    x++;
                                }
                                jam = jam+d+1;

                                if (x == line + 1) {
                                    if (matn[d] == 0) {
                                        printf("line %d doesnt have %d characters. \n", line, d);
                                        marko = 1;
                                    } else {
                                        printf("The string in the order was successfully removed!\n");

                                        char d_matn[1000];
                                        int k = d, andaze = size + d , d_mark=0;
                                        if (go == 1) {

                                            for (int zh = 0; zh < d; ++zh) {
                                                d_matn[zh] = matn[zh];
                                            }

                                            for (int zh = d; zh < 1000; ++zh) {
                                                d_matn[zh] = 0;
                                            }

                                            while (k < andaze) {
                                                if (matn[k] == 0) {
                                                    d_mark =1;
                                                    if(!fgets(matn, 1000, fptr)) {
                                                        marko = 1;
                                                        printf("The size is too big!\n");
                                                    }

                                                    andaze = andaze - k;
                                                    k = -1;
                                                }
                                                k++;
                                            }
                                            for (int l = andaze; l < 1000; ++l) {
                                                new_matn[l - andaze] = matn[l];
                                            }
                                            for (int l = 1000 - andaze; l < 1000; ++l) {
                                                new_matn[l] = 0;
                                            }

                                        }
                                        else
                                        {
                                            jam =  jam - size;

                                            if(jam<=0)
                                            {
                                                marko = 1;
                                                printf("The size is too big!\n");
                                            }

                                            fclose(fp);
                                            fclose(fptr);
                                            fptr = fopen(address, "r");
                                            fp = fopen("C:/users/erfan/ClionProjects/untitled4/root/r_file_r.txt", "w");
                                            int counter = 0, inner=0,pre =0;
                                            while(counter<jam)
                                            {
                                                fgets(d_matn, 1000, fptr);
                                                inner = 0;
                                                while(d_matn[inner] !=0 && counter<jam)
                                                {
                                                    counter++;
                                                    inner++;
                                                }
                                                if(d_matn[inner]==0) {

                                                    fprintf(fp, "%s", d_matn);

                                                    pre = counter;

                                                }
                                            }
                                            andaze = jam - pre;

                                            for (int l = andaze; l <1000 ; ++l) {
                                                d_matn[l] = 0;
                                            }

                                            for (int l = d+1; l < 1000; ++l) {
                                                new_matn[l-d-1] = matn[l];
                                            }
                                            for (int l = 1000-d-1; l < 1000; ++l) {
                                                new_matn[l] = 0;
                                            }
                                            fclose(fp);
                                            fp = fopen("C:/users/erfan/ClionProjects/untitled4/root/r_file_r.txt", "a");

                                        }

                                        fprintf(fp, "%s", d_matn);
                                        fprintf(fp, "%s", new_matn);

                                        int u = 0;
                                        fclose(fptr);
                                        fptr = fopen(address,"r");
                                        while (u<line) {
                                            fgets(matn, 1000, fptr);
                                            u++;
                                        }
                                        while(fgets(matn, 1000, fptr)) {
                                            fprintf(fp, "%s", matn);
                                        }
                                    }

                                }
                                else
                                    printf("The file doesnt have %d lines", line);

                                if (!marko) {
                                    fclose(fp);
                                    fclose(fptr);

                                    fp = fopen("C:/users/erfan/ClionProjects/untitled4/root/r_file_r.txt", "r");
                                    fptr = fopen(address, "w");

                                    while (fgets(patn, 1000, fp))
                                        fprintf(fptr, "%s", patn);

                                }
                            }


                            fclose(fp);
                            fclose(fptr);
                            remove("C:/users/erfan/ClionProjects/untitled4/root/r_file_r.txt");
                        }
                        else
                            printf("invalid command.\n");
                    }

                    else
                        printf("invalid command.\n");
                }
            }
            else
                printf("invalid command.\n");
        }
        else if(check(order, o_copy))
        {
            if(check_mode(mode, m_file))
            {
                int mark = get_address(s,i,address);
                i = mark/10;
                mark = mark % 10;
                if(!mark)
                {
                    for (int k = 0; k < 10; ++k) {
                        mode[k] = 0;
                    }
                    while(s[i] != ' ' && j<10)
                    {
                        mode[j] = s[i];
                        j++;
                        i++;
                    }
                    while (s[i]==' ')
                        i++;
                    if(check_mode(mode, m_pos))
                    {
                        while (s[i] == ' ')
                            i++;

                        int d, x = 1, line, size;

                        line = s[i] - 48;
                        i++;

                        while (s[i] != 58) {
                            line = line * 10 + s[i] - 48;
                            i++;
                        }

                        if (s[i] != 58) {
                            printf("invalid command.\n");
                            mark = 1;
                        } else {
                            i++;
                            d = s[i] - 48;
                            i++;
                            while (s[i] != ' ' && s[i] != 0) {
                                d = d * 10 + s[i] - 48;
                                i++;
                            }
                            while (s[i] == ' ')
                                i++;
                        }
                        if (mark != 1) {
                            char mode_2[10];
                            for (int k = 0; k < 10; ++k) {
                                mode_2[k] = 0;
                            }
                            j = 0;
                            while (s[i] != ' ' && j<10) {
                                mode_2[j] = s[i];
                                i++;
                                j++;
                            }
                            if (check_mode(mode_2, m_size)) {
                                while (s[i] == ' ')
                                    i++;
                            } else {
                                mark = 1;
                                printf("invalid command.\n");
                            }
                        }
                        int go = 0;

                        if (mark != 1) {
                            size = s[i] - 48;
                            i++;
                            while (s[i] != ' ') {
                                size = size * 10 + s[i] - 48;
                                i++;
                            }

                            while (s[i] == ' ')
                                i++;

                            for (int k = 0; k < 10; ++k) {
                                mode[k] = 0;
                            }
                            j = 0;
                            while (s[i] != ' ' && s[i] != 0 && j<10) {
                                mode[j] = s[i];
                                j++;
                                i++;
                            }

                            while (s[i] == ' ')
                                i++;

                            if (s[i] == 0) {

                                if (check_mode(mode, m_b))
                                    go = -1;
                                else if (check_mode(mode, m_f))
                                    go = 1;
                                else
                                    mark = 1;
                            } else
                                mark = 1;
                        }
                        if(!mark)
                        {
                            char matn[1000], new_matn[1000], patn[1000];
                            int jam=0;

                            fptr = fopen(address, "r");

                            if(fptr==NULL)
                                printf("No such file or directory.\n");
                            else
                            {
                                while (x <= line && fgets(matn, 1000, fptr)) {
                                    if (x != line) {
                                        j = 0;
                                        while (matn[j]!=0)
                                        {
                                            jam++;
                                            j++;
                                        }
                                    }
                                    x++;
                                }
                                jam = jam+d+1;

                                int marko = 0;

                                if (x == line + 1) {
                                    if (matn[d] == 0) {
                                        printf("line %d doesnt have %d characters. \n", line, d);
                                        marko = 1;
                                    } else {


                                        char d_matn[1000];
                                        for (int l = 0; l < 4000; ++l) {
                                            clip[l] = 0;
                                        }
                                        int k = d, andaze = size + d, markio=0;
                                        j = 0;
                                        if (go == 1) {
                                            char new_clip[4000];
                                            while (k < andaze) {
                                                if (matn[k] == 0) {

                                                    if(!fgets(matn, 1000, fptr)) {
                                                        printf("The size is too big.\n");
                                                        markio = 1;
                                                        break;
                                                    }

                                                    andaze = andaze - k;
                                                    k = -1;
                                                }
                                                else {
                                                    new_clip[j] = matn[k];
                                                    j++;
                                                }
                                                k++;

                                            }

                                            if(!markio)
                                            {
                                                printf("The string in the order was successfully copied!\n");
                                                for (int l = 0; l < j; ++l) {
                                                    clip[l] = new_clip[l];
                                                }
                                            }
                                            j=0;
                                        }
                                        else
                                        {
                                            jam =  jam - size;

                                            if(jam<=0)
                                                printf("The size is too big!\n");
                                            else
                                            {
                                                printf("The string in the order was successfully copied!\n");
                                                fclose(fptr);
                                                fptr = fopen(address, "r");

                                                int counter = 0, inner=0,pre =0;
                                                while(counter<jam)
                                                {
                                                    fgets(d_matn, 1000, fptr);
                                                    inner = 0;
                                                    while(d_matn[inner] !=0 && counter<jam)
                                                    {
                                                        counter++;
                                                        inner++;
                                                    }

                                                    if(d_matn[inner]==0)
                                                        pre = counter;

                                                }
                                                k = jam -pre;
                                                andaze = k+size;
                                                j = 0;

                                                while (k < andaze) {
                                                    if (d_matn[k] == 0) {

                                                        fgets(d_matn, 1000, fptr);

                                                        andaze = andaze - k;
                                                        k = -1;
                                                    }
                                                    else {
                                                        clip[j] = d_matn[k];
                                                        j++;
                                                    }
                                                    k++;

                                                }
                                                j=0;
                                            }

                                        }

                                    }

                                }
                                else
                                    printf("The file doesnt have %d lines", line);
                            }
                            fclose(fptr);

                        }
                    }
                    else
                        printf("invalid command.\n");
                }
            }
            else
                printf("invalid command.\n");
        }
        else if(check(order, o_cut))
        {
            if(check_mode(mode, m_file))
            {
                int mark = get_address(s,i,address);
                i = mark/10;
                mark = mark % 10;
                if(!mark)
                {
                    for (int k = 0; k < 10; ++k) {
                        mode[k] = 0;
                    }
                    while(s[i] != ' ' && j<10)
                    {
                        mode[j] = s[i];
                        j++;
                        i++;
                    }
                    while (s[i]==' ')
                        i++;
                    if(check_mode(mode, m_pos))
                    {
                        while (s[i] == ' ')
                            i++;

                        int d, x = 1, line, size;

                        line = s[i] - 48;
                        i++;

                        while (s[i] != 58) {
                            line = line * 10 + s[i] - 48;
                            i++;
                        }

                        if (s[i] != 58) {
                            printf("invalid command.\n");
                            mark = 1;
                        } else {
                            i++;
                            d = s[i] - 48;
                            i++;
                            while (s[i] != ' ' && s[i] != 0) {
                                d = d * 10 + s[i] - 48;
                                i++;
                            }
                            while (s[i] == ' ')
                                i++;
                        }
                        if (mark != 1) {
                            char mode_2[10];
                            for (int k = 0; k < 10; ++k) {
                                mode_2[k] = 0;
                            }
                            j = 0;
                            while (s[i] != ' ' && j<10) {
                                mode_2[j] = s[i];
                                i++;
                                j++;
                            }
                            if (check_mode(mode_2, m_size)) {
                                while (s[i] == ' ')
                                    i++;
                            } else {
                                mark = 1;
                                printf("invalid command.\n");
                            }
                        }
                        int go = 0;

                        if (mark != 1) {
                            size = s[i] - 48;
                            i++;
                            while (s[i] != ' ') {
                                size = size * 10 + s[i] - 48;
                                i++;
                            }

                            while (s[i] == ' ')
                                i++;

                            for (int k = 0; k < 10; ++k) {
                                mode[k] = 0;
                            }
                            j = 0;
                            while (s[i] != ' ' && s[i] != 0 && j<10) {
                                mode[j] = s[i];
                                j++;
                                i++;
                            }

                            while (s[i] == ' ')
                                i++;

                            if (s[i] == 0) {

                                if (check_mode(mode, m_b))
                                    go = -1;
                                else if (check_mode(mode, m_f))
                                    go = 1;
                                else
                                    mark = 1;
                            } else
                                mark = 1;
                        }
                        if(!mark)
                        {
                            int marko=0,markio=0;

                            char matn[1000], new_matn[1000], patn[1000];
                            int jam=0;

                            fptr = fopen(address, "r");
                            FILE * fp = fopen("C:/users/erfan/ClionProjects/untitled4/root/r_file_r.txt", "a");

                            if(fptr==NULL) {
                                printf("No such file.\n");
                                markio = 1;
                            }
                            else{
                                while (x <= line && fgets(matn, 1000, fptr)) {
                                    if (x != line) {
                                        fprintf(fp, "%s", matn);
                                        j = 0;
                                        while (matn[j]!=0)
                                        {
                                            jam++;
                                            j++;
                                        }
                                    }
                                    x++;
                                }
                                jam = jam+d+1;

                                if (x == line + 1) {
                                    if (matn[d] == 0) {
                                        printf("line %d doesnt have %d characters. \n", line, d);
                                        marko = 1;
                                    } else {


                                        char d_matn[1000];
                                        for (int l = 0; l < 4000; ++l) {
                                            clip[l] = 0;
                                        }
                                        int k = d , andaze = size + d ;
                                        j = 0;
                                        if (go == 1) {
                                            char new_clip[4000];
                                            while (k < andaze) {
                                                if (matn[k] == 0) {

                                                    if (!fgets(matn, 1000, fptr)) {
                                                        printf("The size is too big.\n");
                                                        markio = 1;
                                                        break;
                                                    }

                                                    andaze = andaze - k;
                                                    k = -1;
                                                } else {
                                                    new_clip[j] = matn[k];
                                                    j++;
                                                }
                                                k++;

                                            }
                                            fclose(fptr);
                                            fptr = fopen(address, "r");
                                            for (int l = 0; l < 1000; ++l) {
                                                d_matn[l] = 0;
                                            }
                                            x = 1;
                                            while (x<=line){
                                                fgets(matn, 1000, fptr);
                                                x++;
                                            }

                                            k = d , andaze = size + d ;
                                            int d_mark = 0;

                                            for (int zh = 0; zh < d ; ++zh) {
                                                d_matn[zh] = matn[zh];
                                            }

                                            for (int zh = d ; zh < 1000; ++zh) {
                                                d_matn[zh] = 0;
                                            }

                                            while (k < andaze) {
                                                if (matn[k] == 0) {
                                                    d_mark = 1;
                                                    fgets(matn, 1000, fptr);

                                                    andaze = andaze - k;
                                                    k = -1;
                                                }
                                                k++;
                                            }
                                            for (int l = andaze; l < 1000; ++l) {
                                                new_matn[l - andaze] = matn[l];
                                            }
                                            for (int l = 1000 - andaze; l < 1000; ++l) {
                                                new_matn[l] = 0;
                                            }


                                            if (!markio) {
                                                printf("The string in the comment was successfully cut!\n");
                                                for (int l = 0; l < j; ++l) {
                                                    clip[l] = new_clip[l];
                                                }
                                            }
                                            j = 0;
                                        } else {
                                            jam = jam - size;

                                            if (jam < 0)
                                                printf("The size is too big!\n");
                                            else {
                                                printf("The string in the order was successfully cut!\n");
                                                fclose(fptr);
                                                fptr = fopen(address, "r");

                                                int counter = 0, inner = 0, pre = 0;
                                                while (counter < jam) {
                                                    fgets(d_matn, 1000, fptr);
                                                    inner = 0;
                                                    while (d_matn[inner] != 0 && counter < jam) {
                                                        counter++;
                                                        inner++;
                                                    }

                                                    if (d_matn[inner] == 0)
                                                        pre = counter;

                                                }
                                                k = jam - pre;
                                                andaze = k + size;
                                                j = 0;

                                                while (k < andaze) {
                                                    if (d_matn[k] == 0) {

                                                        fgets(d_matn, 1000, fptr);

                                                        andaze = andaze - k;
                                                        k = -1;
                                                    } else {
                                                        clip[j] = d_matn[k];
                                                        j++;
                                                    }
                                                    k++;

                                                }
                                                j = 0;

                                                fclose(fp);
                                                fclose(fptr);
                                                fptr = fopen(address, "r");
                                                fp = fopen("C:/users/erfan/ClionProjects/untitled4/root/r_file_r.txt",
                                                           "w");
                                                counter = 0;
                                                inner = 0;
                                                pre = 0;
                                                while (counter < jam) {
                                                    fgets(d_matn, 1000, fptr);
                                                    inner = 0;
                                                    while (d_matn[inner] != 0 && counter < jam) {
                                                        counter++;
                                                        inner++;
                                                    }
                                                    if (d_matn[inner] == 0) {

                                                        fprintf(fp, "%s", d_matn);

                                                        pre = counter;

                                                    }
                                                }
                                                andaze = jam - pre;

                                                for (int l = andaze; l < 1000; ++l) {
                                                    d_matn[l] = 0;
                                                }

                                                for (int l = d+1; l < 1000; ++l) {
                                                    new_matn[l - d-1] = matn[l];
                                                }
                                                for (int l = 1000 - d-1; l < 1000; ++l) {
                                                    new_matn[l] = 0;
                                                }
                                                fclose(fp);
                                                fp = fopen("C:/users/erfan/ClionProjects/untitled4/root/r_file_r.txt",
                                                           "a");


                                            }

                                        }
                                        fprintf(fp, "%s", d_matn);
                                        fprintf(fp, "%s", new_matn);

                                        int u = 0;
                                        fclose(fptr);
                                        fptr = fopen(address,"r");
                                        while (u<line) {
                                            fgets(matn, 1000, fptr);
                                            u++;
                                        }
                                        while(fgets(matn, 1000, fptr)) {
                                            fprintf(fp, "%s", matn);
                                        }
                                    }

                                }
                                else
                                    printf("The file doesnt have %d lines", line);

                            }

                            if(!marko && !markio)
                            {

                                fclose(fp);
                                fclose(fptr);

                                fp = fopen("C:/users/erfan/ClionProjects/untitled4/root/r_file_r.txt", "r");
                                fptr = fopen(address, "w");

                                while (fgets(patn, 1000, fp))
                                    fprintf(fptr, "%s", patn);
                            }
                            fclose(fp);
                            fclose(fptr);
                            remove("C:/users/erfan/ClionProjects/untitled4/root/r_file_r.txt");
                        }
                    }
                    else
                        printf("invalid command.\n");
                }
            }
            else
                printf("invalid command.\n");
        }
        else if(check(order, o_paste))
        {
            if (check_mode(mode, m_file)) {
                while (s[i] == ' ')
                    i++;

                int mark = get_address(s, i, address);
                i = mark/10;

                if (mark % 10 == 0) {
                    fptr = fopen(address, "r");

                    if (fptr == NULL)
                        mark = 1;

                    fclose(fptr);

                    if (mark == 1)
                        printf("No such file .\n");
                    else {
                        char mode_2[10];

                        j = 0;
                        while (s[i] != ' ' && j<10) {
                            mode_2[j] = s[i];
                            i++;
                            j++;
                        }
                        while(j<10) {
                            mode_2[j] = 0;
                            j++;
                        }
                        j = 0;

                        if (check_mode(mode_2, m_pos)) {

                            while (s[i] ==' ')
                                i++;

                            int d, x=1, line;

                            line = s[i] - 48;
                            i++;

                            while (s[i]!=58) {
                                line = line * 10 + s[i] - 48;
                                i++;
                            }

                            if(s[i]!=58)
                            {
                                printf("invalid command.\n");
                                mark = 1;
                            }
                            else
                            {
                                i++;
                                d = s[i] - 48;
                                i++;
                                while (s[i]!=' '&&s[i]!=0)
                                {
                                    d = d* 10 + s[i] -48;
                                    i++;
                                }
                                while (s[i] ==' ')
                                    i++;
                                if(s[i]!=0)
                                {
                                    printf("invalid command.\n");
                                    mark = 1;
                                }
                            }

                            if(mark!=1)
                            {
                                char matn[1000], new_matn[1000],patn[1000];

                                fptr = fopen(address, "r");

                                FILE * fp = fopen("C:/users/erfan/ClionProjects/untitled4/root/r_file_r.txt", "a");

                                while (x <= line && fgets(matn, 1000, fptr)) {
                                    if(x != line)
                                    {
                                        fprintf(fp, "%s", matn);
                                    }
                                    x++;
                                }

                                int marko = 0;

                                if (x == line+1)
                                {
                                    if(matn[d-1] == 0 && d!=0) {
                                        printf("line %d doesnt have %d characters. \n", line, d);
                                        marko = 1;
                                    }
                                    else
                                    {
                                        printf("The string in clipboard was pasted at ordered position successfully!\n");
                                        for (int k = d; k < 1000; ++k) {
                                            new_matn[k-d] = matn[k];
                                            matn[k] = 0;
                                        }

                                        fprintf(fp, "%s", matn);

                                        marko = print_text(clip, fp);

                                        fprintf(fp, "%s", new_matn);
                                        while (fgets(matn,1000,fptr))
                                            fprintf(fp, "%s",matn);
                                    }
                                    if(!marko)
                                    {
                                        fclose(fp);
                                        fclose(fptr);

                                        fp = fopen("C:/users/erfan/ClionProjects/untitled4/root/r_file_r.txt", "r");
                                        fptr = fopen(address, "w");

                                        while (fgets(patn, 1000, fp))
                                            fprintf(fptr, "%s", patn);
                                    }
                                }
                                else if(x==line)
                                {
                                    printf("The string in the order was successfully pasted!\n");

                                    fclose(fptr);
                                    fptr = fopen(address, "a");
                                    if(line!=1)
                                        fprintf(fptr, "\n");
                                    fprintf(fptr, "%s", clip);
                                }
                                else {
                                    printf("The file doesnt have %d lines.\n", line);
                                    marko = 1;
                                }

                                fclose(fp);
                                fclose(fptr);
                                remove("C:/users/erfan/ClionProjects/untitled4/root/r_file_r.txt");
                            }

                        }
                        else
                            printf("invalid command.\n");

                    }
                }
            }
            else
                printf("invalid command.\n");
        }
        else if(check(order, o_find))
        {
            if(check_mode(mode, m_str))
            {
                int mark = get_text(s,i,text);
                i = mark/10;
                mark = mark % 10;

                if(mark ==0)
                {
                    for (int k = 0; k < 10; ++k) {
                        mode[k] = 0;
                    }
                    j = 0;
                    while (s[i] != ' ' && j<10)
                    {
                        mode[j] = s[i];
                        i++;
                        j++;
                    }
                    for ( j; j <10 ; ++j) {
                        mode[j]= 0;
                    }
                    if(check_mode(mode, m_file))
                    {
                        while(s[i] ==' ')
                            i++;

                        mark = get_address(s,i,address);
                        i = mark/10;
                        mark = mark % 10;

                        if(!mark)
                        {
                            char matn[1000];

                            int k,f=0;

                            fptr = fopen(address, "r");

                            while (fgets(matn, 1000, fptr))
                            {
                                k = 0;
                                while (matn[k]!=0)
                                {
                                    fff[f] = matn[k];
                                    f++;
                                    k++;
                                }
                            }
                            k=0;
                            while (text[k]!=0)
                                k++;
                            int size = k;

                            for (int l = f; l <f+5 ; ++l) {
                                fff[l] = 0;
                            }

                            if(s[i]!=0)
                            {
                                j=0;
                                while (s[i]!=' ' && s[i]!=0) {
                                    mode[j] = s[i];
                                    j++;
                                    i++;
                                }
                                for (j; j < 10; ++j) {
                                    mode[j] = 0;
                                }

                                if(check_mode(mode,m_count))
                                {
                                    int found = 0;
                                    j=0;
                                    while (j<f-size+1)
                                    {
                                        k = 0;
                                        while (k<size)
                                        {
                                            if(fff[j+k] == text[k])
                                                k++;
                                            else
                                                break;
                                        }
                                        if(k==size)
                                            found++;
                                        j++;
                                    }
                                    printf("%d \n", found);
                                }
                                else if(check_mode(mode, m_at))
                                {
                                    while (s[i] ==' ')
                                        i++;

                                    int at = s[i] - 48;
                                    i++;

                                    while (s[i]<58 && s[i]>47) {
                                        at = at * 10 + s[i] - 48;
                                        i++;
                                    }
                                    if(s[i]!=' ' && s[i]!=0)
                                        printf("invalid command.\n");
                                    else
                                    {
                                        while (s[i] ==' ')
                                            i++;
                                        if(s[i]!=0)
                                            printf("invalid command.\n");
                                        else
                                        {
                                            int found = -1,counter=0;
                                            j=0;
                                            while (j<f-size +1 && counter<at)
                                            {
                                                k = 0;
                                                while (k<size)
                                                {
                                                    if(fff[j+k] == text[k])
                                                        k++;
                                                    else
                                                        break;
                                                }
                                                if(k==size)
                                                {
                                                    found = j;
                                                    counter++;
                                                }
                                                j++;
                                            }
                                            if(counter==at)
                                                printf("%d \n", found);
                                            else
                                                printf("%d\n", -1);
                                        }
                                    }

                                }
                                else if(check_mode(mode, m_all))
                                {
                                    int found = -1;
                                    j=0;
                                    while (j<f-size+1 )
                                    {
                                        k = 0;
                                        while (k<size)
                                        {
                                            if(fff[j+k] == text[k])
                                                k++;
                                            else
                                                break;
                                        }
                                        if(k==size)
                                        {
                                            found = 1;
                                            printf("%d ", j);

                                        }
                                        j++;
                                    }
                                    if(found==-1)
                                        printf("%d\n", -1);
                                    else
                                        printf("\n");

                                }
                                else if(check_mode(mode, m_byword)) {

                                    int found = -1;
                                    j=0;
                                    while (j<f-size+1)
                                    {
                                        k = 0;
                                        while (k<size)
                                        {
                                            if(fff[j+k] == text[k])
                                                k++;
                                            else
                                                break;
                                        }
                                        if(k==size)
                                        {
                                            found = j;
                                            break;
                                        }
                                        else
                                            j++;
                                    }

                                    j=0;
                                    fclose(fptr);
                                    fptr = fopen(address, "r");
                                    fgets(matn, 1000, fptr);
                                    int found2 = found, javab=1;

                                    while (j<found)
                                    {
                                        k=0;

                                        while (matn[k]!=0 && k<found2) {
                                            while (matn[k] ==' ')
                                                k++;
                                            while (matn[k]!=0 && matn[k]!=' ' && k<found2)
                                            {
                                                k++;
                                            }
                                            j=k;
                                            if(k==found2)
                                                break;

                                            else if(matn[k]==0) {
                                                found2 = found2 - k;
                                                k=0;
                                                fgets(matn, 1000, fptr);
                                                javab++;
                                            }
                                            else
                                                javab++;
                                        }
                                        if (k==found2)
                                            break;

                                    }
                                    printf("%d \n", javab);
                                }
                                else
                                    printf("invalid command.\n");
                            }
                            else
                            {
                                int found = -1;
                                j=0;
                                while (j<=f-size)
                                {
                                    k = 0;
                                    while (k<size)
                                    {
                                        if(fff[j+k] == text[k])
                                            k++;
                                        else
                                            break;
                                    }
                                    if(k==size)
                                    {
                                        found = j;
                                        break;
                                    }
                                    else
                                        j++;
                                }
                                printf("%d \n", found);
                            }

                        }
                    }
                    else
                        printf("invalid command.\n");
                }
            }
            else
                printf("invalid command.\n");
        }
        else if(check(order, o_replace))
        {
            if(check_mode(mode, m_str1))
            {
                int mark = get_text(s,i,text);
                i = mark/10;
                mark = mark % 10;

                if(mark ==0)
                {
                    for (int k = 0; k < 10; ++k) {
                        mode[k] = 0;
                    }
                    j = 0;
                    while (s[i] != ' ' && j<10)
                    {
                        mode[j] = s[i];
                        i++;
                        j++;
                    }
                    for ( j; j <10 ; ++j) {
                        mode[j]= 0;
                    }
                    if(check_mode(mode, m_str2))
                    {
                        while(s[i] ==' ')
                            i++;

                        char text2[1000];

                        for (int k = 0; k < 1000; ++k) {
                            text2[k] = 0;
                        }

                        mark = get_text(s,i,text2);
                        i = mark/10;
                        mark = mark % 10;

                        if(!mark)
                        {
                            for (int k = 0; k < 10; ++k) {
                                mode[k] = 0;
                            }
                            j=0;

                            while (s[i]!= ' ') {
                                mode[j] = s[i];
                                i++;
                                j++;
                            }
                            while (s[i]==' ')
                                i++;
                            if(check_mode(mode, m_file))
                            {
                                while (s[i] == ' ')
                                    i++;

                                mark = get_address(s,i,address);
                                i = mark/10;
                                mark = mark%10;

                                fptr = fopen(address, "r");
                                if(fptr==NULL)
                                {
                                    printf("invalid address.\n");
                                    mark =1;
                                }

                                if(!mark)
                                {
                                    char matn[1000];
                                    for (int k = 0; k < 1000; ++k) {
                                        matn[k] = 0;
                                    }

                                    int k,f=0;

                                    while (fgets(matn, 1000, fptr))
                                    {
                                        k = 0;
                                        while (matn[k]!=0)
                                        {
                                            fff[f] = matn[k];
                                            f++;
                                            k++;
                                        }
                                    }
                                    k=0;
                                    while (text[k]!=0)
                                        k++;
                                    int size = k;

                                    for (int l = f; l <f+5 ; ++l) {
                                        fff[l] = 0;
                                    }

                                    if(s[i]!=0)
                                    {
                                        j=0;
                                        while (s[i]!=' ' && s[i]!=0) {
                                            mode[j] = s[i];
                                            j++;
                                            i++;
                                        }
                                        for (j; j < 10; ++j) {
                                            mode[j] = 0;
                                        }

                                        if(check_mode(mode, m_at))
                                        {
                                            while (s[i] ==' ')
                                                i++;

                                            int at = s[i] - 48;
                                            i++;

                                            while (s[i]<58 && s[i]>47) {
                                                at = at * 10 + s[i] - 48;
                                                i++;
                                            }
                                            if(s[i]!=' ' && s[i]!=0)
                                                printf("invalid command.\n");
                                            else
                                            {
                                                while (s[i] ==' ')
                                                    i++;
                                                if(s[i]!=0)
                                                    printf("invalid command.\n");
                                                else
                                                {
                                                    int found = -1,counter=0;
                                                    j=0;
                                                    while (j<f-size +1 && counter<at)
                                                    {
                                                        k = 0;
                                                        while (k<size)
                                                        {
                                                            if(fff[j+k] == text[k])
                                                                k++;
                                                            else
                                                                break;
                                                        }
                                                        if(k==size)
                                                        {
                                                            found = j;
                                                            counter++;
                                                        }
                                                        j++;
                                                    }

                                                    if(counter!=at)
                                                        printf("There are less than %d %s in this file\n", at,text);
                                                    else
                                                    {
                                                        printf("The string2 was successfully replaced into the file.\n");
                                                        int size2 = 0;
                                                        j=0;
                                                        while (text2[j]!=0)
                                                        {
                                                            size2 ++;
                                                            j++;
                                                        }
                                                        int d = size2 -size;

                                                        if(d>=0)
                                                        {
                                                            for (int l = 9999; l >=found+size2 ; --l) {
                                                                fff[l] = fff[l-d];
                                                            }
                                                        }
                                                        else
                                                        {
                                                            for (int l = found+size2; l <10000 ; ++l) {
                                                                fff[l] = fff[l-d];
                                                            }
                                                        }

                                                        for (int l = found; l <found+size2 ; ++l) {
                                                            fff[l] = text2[l-found];
                                                        }
                                                        fclose(fptr);
                                                        fptr = fopen(address, "w");
                                                        fprintf(fptr, "%s", fff);

                                                    }
                                                }
                                            }

                                        }
                                        else if(check_mode(mode, m_all)) {
                                            int found = -1;
                                            j = 0;
                                            while (j < f - size + 1) {
                                                k = 0;
                                                while (k < size) {
                                                    if (fff[j + k] == text[k])
                                                        k++;
                                                    else
                                                        break;
                                                }
                                                if (k == size) {
                                                    found = j;

                                                    int size2 = 0;
                                                    j=0;
                                                    while (text2[j]!=0)
                                                    {
                                                        size2 ++;
                                                        j++;
                                                    }
                                                    int d = size2 -size;

                                                    if(d>=0)
                                                    {
                                                        for (int l = 9999; l >=found+size2 ; --l) {
                                                            fff[l] = fff[l-d];
                                                        }
                                                    }
                                                    else
                                                    {
                                                        for (int l = found+size2; l <10000 ; ++l) {
                                                            fff[l] = fff[l-d];
                                                        }
                                                    }

                                                    for (int l = found; l <found+size2 ; ++l) {
                                                        fff[l] = text2[l-found];
                                                    }
                                                    fclose(fptr);
                                                    fptr = fopen(address, "w");
                                                    fprintf(fptr, "%s", fff);

                                                }
                                                j++;
                                            }
                                            if (found == -1)
                                                printf("There are no %s in this file.\n", text);
                                            else
                                                printf("String2 was successfully replaced into the file.\n");

                                        }
                                        else
                                            printf("invalid command.\n");
                                    }
                                    else
                                    {
                                        int found = -1;
                                        j=0;
                                        while (j<=f-size)
                                        {
                                            k = 0;
                                            while (k<size)
                                            {
                                                if(fff[j+k] == text[k])
                                                    k++;
                                                else
                                                    break;
                                            }
                                            if(k==size)
                                            {
                                                found = j;
                                                break;
                                            }
                                            else
                                                j++;
                                        }
                                        if(found==-1)
                                            printf("Theres no %s in this file.\n", text);
                                        else
                                        {
                                            printf("The str2 was successfully replaced into the file.\n");
                                            int size2 = 0;
                                            j=0;
                                            while (text2[j]!=0)
                                            {
                                                size2 ++;
                                                j++;
                                            }
                                            int d = size2 -size;

                                            if(d>=0)
                                            {
                                                for (int l = 9999; l >=found+size2 ; --l) {
                                                    fff[l] = fff[l-d];
                                                }
                                            }
                                            else
                                            {
                                                for (int l = found+size2; l <10000 ; ++l) {
                                                    fff[l] = fff[l-d];
                                                }
                                            }

                                            for (int l = found; l <found+size2 ; ++l) {
                                                fff[l] = text2[l-found];
                                            }
                                            fclose(fptr);
                                            fptr = fopen(address, "w");
                                            fprintf(fptr, "%s", fff);

                                        }
                                    }
                                }
                                fclose(fptr);
                            }

                        }
                    }
                    else
                        printf("invalid command.\n");
                }
            }
            else
                printf("invalid command.\n");
        }
        else if(check(order, o_grep))
        {

        }
        else if(check(order, o_closingpairs))
        {

        }
        else if(check(order, o_undo))
        {

        }
        else if(check(order, o_tree))
        {

        }
        else if(check(order, o_compare))
        {

        }
        else
            printf("invalid command. \n");

    }

    return  0;
}
