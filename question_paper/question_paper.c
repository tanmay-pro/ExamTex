#include"../function_def.h"
#include "question_paper.h"

struct questions add_question_type()
{
    char ch,buffer[100];
    float difficulty;
    struct questions que;
    ///////Checking if command is sample//////////
    ch=getchar();
    while(ch == ' ')
        ch=getchar();
    int j=0;
    while( (ch != ' ') && (ch != '{') )
    {
        buffer[j]=ch;
        j++;
        ch=getchar();
    }       
    buffer[j]='\0';
    while(ch != '{')
        ch=getchar();
    /////////////////////
    if(!strcmp(buffer,"sample"))
    {   
        ///////Checking the type of question////////////
        while(ch != '{')
            ch=getchar();        
        scanf("%[^=]s",buffer);
        while(ch != '=')
            ch=getchar();
        ch=getchar();
        while(ch == ' ')
            ch=getchar();
        int i=0;
        while( (ch != ' ') && (ch != '}') )
        {
            buffer[i]=ch;
            i++;
            ch=getchar();
        }
        buffer[i]='\0';
        while(ch != '}')
            ch=getchar();    
        //!!!!!!!!!!!!!!!!add the different question types here!!!!!!!!!!!!!!!!!
        if(!strcmp(buffer,"mcq"))   
            que.type=44;
        if(!strcmp(buffer,"scq"))
            que.type=55;
        while(ch != '}')
            ch=getchar();
        //printf("%d\n",que.type);
        //////////reading the difficulty of the questions///////////////
        while(ch != '{')
            ch=getchar();
        scanf("%[^=]s",buffer);
        while(ch != '=')
            ch=getchar();
        scanf("%f",&que.diff);
        while(ch != '}')
            ch=getchar();
        //printf("%f\n",que.diff);
        while(ch != '{')
            ch=getchar();
        scanf("%[^=]s",buffer);
        while(ch != '=')
            ch=getchar();
        scanf(" %d",&que.no_of_questions);
        while(ch != '}')
            ch=getchar();   
        //printf("%d\n",que.no_of_questions);
    }
    return que;
}

void read_question_paper()
{
    char ch,buffer[100];
    struct questions questions_in_paper[5];
    int i=0;
    ch=getchar();
    while(ch != '.')   //eof here!!!
    {
        while(ch != 92)
            ch=getchar();
        questions_in_paper[i]=add_question_type();
    
        i++;
        ch=getchar();
    }
    //for(int j=0;j<i;j++)
    //   printf("%d %.2f %d\n",questions_in_paper[j].type,questions_in_paper[j].diff,questions_in_paper[j].no_of_questions);
}
