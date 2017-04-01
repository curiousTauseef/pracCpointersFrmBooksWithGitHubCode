#include <stdio.h>
#include <stdlib.h>

void Build_Frm(int MAC_src[], int IP_src[], int IP_dst[]);
void Show_Frm(unsigned char pkt[], int len);

int main()
{
	int MAC_src[6], IP_src[4], IP_dst[4];

      printf("Enter src MAC (x.x.x.x.x.x): ");
      scanf("%d.%d.%d.%d.%d.%d", &MAC_src[0], &MAC_src[1], &MAC_src[2], &MAC_src[3], &MAC_src[4], &MAC_src[5]);

      printf("Enter src IP (x.x.x.x): ");
      scanf("%d.%d.%d.%d", &IP_src[0], &IP_src[1], &IP_src[2], &IP_src[3]);

      printf("Enter dst IP (x.x.x.x): ");
      scanf("%d.%d.%d.%d", &IP_dst[0], &IP_dst[1], &IP_dst[2], &IP_dst[3]);

	Build_Frm(MAC_src, IP_src, IP_dst);
	return 0;
}

void Build_Frm(int MAC_src[], int IP_src[], int IP_dst[])
{
	unsigned char pkt[54] = {85, 85, 85, 85, 85, 85, 85, 171}; /* Initialize the first eight octets of the frame and zero the rest. */
	int i, j;

	for(i = 8; i < 14; i++)
		pkt[i] = 255; /* Broadcast MAC address. */
	for(i = 14, j = 0; i < 20; i++, j++)
		pkt[i] = MAC_src[j]; /* MAC source. */

	pkt[20] = 8; /* Type. */
	pkt[21] = 6;

	pkt[22] = 0; /* Hardware Type. */
	pkt[23] = 1;

	pkt[24] = 8; /* Protocol Type. */
	pkt[25] = 6;

	pkt[26] = 6; /* Hardware Length. */
	pkt[27] = 4; /* Protocol Length. */

	pkt[28] = 0; /* Operation (ARP_Request). */
	pkt[29] = 1;

	for(i = 30, j = 0; i < 36; i++, j++)
		pkt[i] = MAC_src[j]; /* MAC source. */
	for(i = 36, j = 0; i < 40; i++, j++)
		pkt[i] = IP_src[j]; /* IP source. */
	/* The MAC destination in places [40-45] is initialized to 0. */
	for(i = 46, j = 0; i < 50; i++, j++)
		pkt[i] = IP_dst[j]; /* IP destination. */
	for(i = 50; i < 54; i++)
		pkt[i] = 1; /* CRC. */

	Show_Frm(pkt, i);
}

void Show_Frm(unsigned char pkt[], int len)
{
	int i;
	for(i = 0; i < len; i++)
	{        
		if((i > 0) && (i%16 == 0))
			printf("\n");
		printf("%02X ", pkt[i]);                  
	}
}