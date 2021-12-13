#include <stdio.h>
main() {
  float x,y,z,x0=1.,y0=1.,z0=1.,k1x, k2x,k1y, k2y,k1z, k2z, s=10.,r=28.,b=8./3.,dt=0.001,t=0.;
  int i=0, itrans=1000;
  for (i=0;i<100000;i++) {
    k1x=s*(y0-x0)*dt;
	k1y=(x0*(r-z0)-y0)*dt;
	k1z=(x0*y0-b*z0)*dt;
	k2x=s*(y0+k1y-x0-k1x)*dt;
	k2y=((x0+k1x)*(r-z0-k1z)-y0-k1y)*dt;
	k2z=((x0+k1x)*(y0+k1y)-b*(z0+k1z))*dt;
    x=x0+0.5*(k1x+k2x);
    y=y0+0.5*(k1y+k2y);
    z=z0+0.5*(k1z+k2z);
    x0=x;
    y0=y;
    z0=z;
	t=t+dt;
    if (i>itrans) printf("%f  %f   %f  %f\n", x,y,z,t);
  }
}
