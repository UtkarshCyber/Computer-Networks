#include<stdio.h>
#include<stdlib.h>
void bucket(int send);
void bucketoverflow(int send);
int bucketsize=30,bucketmax=60;
int bucketrate=3;
int main()
{
    int i=0;
    while(i<10)
    {
        printf("\n1.Send packets\n2.Nothing to send\n3.Exit\nEnter your choice:\n");
    int ch;
    scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter the packet size required to be sent:\n");
            int send;
            scanf("%d",&send);
            if(send<bucketmax-bucketsize)
            {
                bucket(send);
                printf("Packets sent successfully\n");
            }
            else{
                printf("Error");
                bucketoverflow(send);
            }
            printf("Bucket size = %d\n",bucketsize);
            break;
        case 2:
            printf("No packets sent\n");
            bucketsize-=3;
            printf("Bucket size = %d\n",bucketsize);
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid option");
        }
        i+=1;
    }
    return 0;
}
void bucket(int send)
{
bucketsize+=send;
bucketsize-=3;
}
void bucketoverflow(int send)
{
bucketsize-=3;
}
