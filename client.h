#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

void error_handling(char *message);

void client(int port)
{
				int sock;
				struct sockaddr_in serv_addr;
				char message[300];
				int str_len;
				int i,x;
				//서버 접속을 위한 소켓 생성
				sock = socket(PF_INET,SOCK_STREAM, 0);
				
				if(sock == -1)
								error_handling("socket ERROR");

				memset(&serv_addr, 0, sizeof(serv_addr));

				serv_addr.sin_family = AF_INET;
				serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
				serv_addr.sin_port = htons(port);
				
				//서버로 연결 요청
				if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
								error_handling("수신된 메시지가 없습니다.\n");
				
				//데이터 수신
				str_len = read(sock, message, sizeof(message)-1);

				message[str_len] = 0;

				printf("메세지가 도착하였습니다 : %s\n", message);
				printf("/n 선택해주십시요:\n");
				printf("1 = 나가기\n");
				printf("2 = 복호화하기\n");
				scanf("%d", &x);
				switch(x){
				case 1:
					break;
				case 2:
				for(i = 0; (i < 100 && message[i] != '\0'); i++)
        			message[i] = message[i] - 3; //the key for encryption is 3 that is subtracted to ASCII value

      printf(" 복호화된 메세지 입니다:: %s\n", message);
      

				//연결 종료
				close(sock);
}
				return;
}

