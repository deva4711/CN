#include <stdio.h>

#include <stdlib.h>

 

int main() {

   int bucket_size, output_rate, n, i;

   int incoming, stored = 0;

 

   printf("Enter the bucket size (in packets): ");

   scanf("%d", &bucket_size);

 

   printf("Enter the output rate (packets per second): ");

   scanf("%d", &output_rate);

 

   printf("Enter the number of incoming packet requests: ");

   scanf("%d", &n);

 

   for (i = 0; i < n; i++) {

       printf("\nEnter the size of incoming packet %d (in packets): ", i+1);

       scanf("%d", &incoming);

 

       printf("Incoming packet size = %d\n", incoming);

 

       // Check if packets can be stored

       if (incoming + stored > bucket_size) {

           int dropped = (incoming + stored) - bucket_size;

           printf("Bucket overflow! Dropped %d packets\n", dropped);

           stored = bucket_size;  // bucket is full

       } else {

           stored += incoming;

       }

 

       // Transmit packets at output rate

       printf("Packets sent: %d\n", (stored < output_rate) ? stored : output_rate);

 

       // Reduce stored packets after sending

       if (stored < output_rate)

           stored = 0;

       else

           stored -= output_rate;

 

       printf("Packets remaining in bucket: %d\n", stored);

   }

 

   // Empty remaining packets in the bucket

   while (stored > 0) {

       printf("\nPackets sent: %d\n", (stored < output_rate) ? stored : output_rate);

       if (stored < output_rate)

           stored = 0;

       else

           stored -= output_rate;

       printf("Packets remaining in bucket: %d\n", stored);

   }

 

   return 0;

}