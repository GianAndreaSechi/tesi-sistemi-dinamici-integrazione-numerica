#include <stdio.h>
main() {
  float x,y,z,x0=1.,y0=1.,z0=1.,k1x, k2x,k1y, k2y,k1z, k2z, s=10.,r=28.,b=8./3.,dt=0.001,t=0.,k3x, k4x,k3y, k4y,k3z, k4z;
  int i=0, itrans=1000;
  for (i=0;i<100000;i++) {
    k1x=s*(y0-x0)*dt;
    k1y=(x0*(r-z0)-y0)*dt;
    k1z=(x0*y0-b*z0)*dt;
    k2x=s*(y0+(0.5*k1y)-x0-(0.5*k1x))*dt;
    k2y=((x0+(0.5*k1x))*(r-z0-(0.5*k1z))-y0-(0.5*k1y))*dt;
    k2z=((x0+(0.5*k1x))*(y0+(0.5*k1y))-b*(z0+(0.5*k1z)))*dt;
    k3x=s*(y0+(0.5*k2y)-x0-(0.5*k2x))*dt;
    k3y=((x0+(0.5*k2x))*(r-z0-(0.5*k2z))-y0-(0.5*k2y))*dt;
    k3z=((x0+(0.5*k2x))*(y0+(0.5*k2y))-b*(z0+(0.5*k2z)))*dt;
    k4x=s*(y0+(k3y)-x0-(k3x))*dt;
    k4y=((x0+(k3x))*(r-z0-(k3z))-y0-(k3y))*dt;
    k4z=((x0+(k3x))*(y0+(k3y))-b*(z0+(k3z)))*dt;
    x=x0+0.16666667*(k1x+2*k2x+2*k3x+k4x);
    y=y0+0.16666667*(k1y+2*k2y+2*k3y+k4y);
    z=z0+0.16666667*(k1z+2*k2z+2*k3z+k4z);
    x0=x;
    y0=y;
    z0=z;
	t=t+dt;
    if (i>itrans) printf("%f  %f   %f  %f\n", x,y,z,t);
  }
}
