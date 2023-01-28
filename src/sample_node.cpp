/*
#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sample_node");
  ros::NodeHandle nh;

  ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("chatter", 1000);

  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    std_msgs::String msg;
    msg.data = "hello world";

    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  FILE *fp;
  int way, oper;
  unsigned int time;
  double lat, lon, alt;

  way = 1;
  time = 151430;
  lat = 36.668422;
  lon = 128.351391;
  alt = 71.50;

  fp = fopen("sample.trj", "wb");

  fwrite(&way, 1, sizeof(way), fp);
  fwrite(&time, 1, sizeof(time), fp);
  fwrite(&lat, 1, sizeof(lat), fp);
  fwrite(&lon, 1, sizeof(lon), fp);
  fwrite(&alt, 1, sizeof(alt), fp);
  fclose(fp);
  return 0;
}
*/


#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
  FILE *fp, *txtPtr;
  int way, oper;
  unsigned int time;
  double lat, lon, alt;
  //int a;
  //fp = fopen("sample.trj", "rb");
  //fp = fopen("gpsdata_little_endian.trj", "rb");
  fp = fopen("/home/ej/gpsdata_little_endian.trj", "rb");
  //txtPtr = fopen("/home/ej/gps_data_LE.txt", "a+");
  txtPtr = fopen("/home/ej/gps_data_LE.txt", "w");
  fputs("way\t time\t latitude\t longitude\t altitude\n", txtPtr);
  while(!feof(fp)) {
    fread(&way, 1, sizeof(int), fp);
    fread(&time, 1, sizeof(int), fp);
    fread(&lat, 1, sizeof(double), fp);
    fread(&lon, 1, sizeof(double), fp);
    fread(&alt, 1, sizeof(double), fp);
    printf("%d\t%d\t\%.6f\t%.6f\t%.2f\n", way, time, lat, lon, alt);
    fprintf(txtPtr, "%d\t%d\t\%.6f\t%.6f\t%.2f\n", way, time, lat, lon, alt);
  }
  fclose(fp);
  fclose(txtPtr);
  return 0;
}
