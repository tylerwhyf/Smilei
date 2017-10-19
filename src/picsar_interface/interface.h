#ifndef INTERFACE_H
#define INTERFACE_H
#include "Field3D.h"
#include "Params.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "ElectroMagn3D.h"
#include <iostream>
extern  "C"
{
	void init_params_picsar(int*,int*,int*,double*,double*,double*,double*,
		int*,int*,int*,int*,int*,int*,bool*,double*,double*,double*,double*,
		double*,double*,double*,double*,double*,double*,double*);
	void push_psatd_ebfield_3d();
        void push_psaotd_ebfields();
	void get_Ffields();
	void get_fields();
        void solve_maxwell_fdtd_pxr();
        
};
void copy_field(Field3D* out, Field3D * in);
void duplicate_field_into_pxr(ElectroMagn*,Params& params );
void duplicate_field_into_smilei(ElectroMagn*,Params& params );

#endif
