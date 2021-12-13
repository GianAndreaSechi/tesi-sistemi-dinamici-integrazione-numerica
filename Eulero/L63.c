#include <stdio.h>
main() {
  float x,y,z,x0=1.,y0=1.,z0=1.,s=10.,r=28.,b=8./3.,dt=0.001,t=0.;
  int i=0, itrans=1000;
  for (i=0;i<100000;i++) {
    x=x0+s*(y0-x0)*dt;
    y=y0+(x0*(r-z0)-y0)*dt;
    z=z0+(x0*y0-b*z0)*dt;
    x0=x;
    y0=y;
    z0=z;
    t=t+dt;
    if (i>itrans) printf("%f  %f   %f  %f\n", x,y,z,t);
  }
}
