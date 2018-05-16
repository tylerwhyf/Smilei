
#ifndef SYNCVECTORPATCH_H
#define SYNCVECTORPATCH_H

#include <vector>

class VectorPatch;
class Params;
class SmileiMPI;
class Field;
class Timers;

class SyncVectorPatch {
public :

    //! Particles synchronization
    static void exchangeParticles(VectorPatch& vecPatches, int ispec, Params &params, SmileiMPI* smpi, Timers &timers, int itime);
    static void finalize_and_sort_parts(VectorPatch& vecPatches, int ispec, Params &params, SmileiMPI* smpi, Timers &timers, int itime);

    //! Densities synchronization
    static void sumRhoJ  ( Params& params, VectorPatch& vecPatches, Timers &timers, int itime );
    //! Densities synchronization per species
    static void sumRhoJs ( Params& params, VectorPatch& vecPatches, int ispec, Timers &timers, int itime );
    //! Densities synchronization per species
    static void sumRhoJs ( Params& params, VectorPatch& vecPatches,int imode, int ispec, Timers &timers, int itime );
    //! Densities synchronization per mode
    static void sumRhoJ  ( Params& params, VectorPatch& vecPatches, int imode, Timers &timers, int itime );
    //! Densities synchronization, including envelope
    static void sumEnvChi  ( Params& params, VectorPatch& vecPatches, Timers &timers, int itime );
    //static void sumEnvChis ( Params& params, VectorPatch& vecPatches, int ispec, Timers &timers, int itime );

    static void sum      ( std::vector<Field*> fields, VectorPatch& vecPatches, Timers &timers, int itime );
    static void sumComplex( std::vector<Field*> fields, VectorPatch& vecPatches, Timers &timers, int itime );
    static void sum_all_components ( std::vector<Field*>& fields, VectorPatch& vecPatches, Timers &timers, int itime );


    //! Fields synchronization
    static void exchangeE( Params& params, VectorPatch& vecPatches );
    static void finalizeexchangeE( Params& params, VectorPatch& vecPatches );
    static void exchangeB( Params& params, VectorPatch& vecPatches );
    static void finalizeexchangeB( Params& params, VectorPatch& vecPatches );
    static void exchangeB( Params& params, VectorPatch& vecPatches, int imode );
    static void finalizeexchangeB( Params& params, VectorPatch& vecPatches, int imode );
    static void exchangeJ( Params& params, VectorPatch& vecPatches );
    static void finalizeexchangeJ( Params& params, VectorPatch& vecPatches );

    static void exchangeA( Params& params, VectorPatch& vecPatches );
    static void finalizeexchangeA( Params& params, VectorPatch& vecPatches );
    static void exchangeGradPhi( Params& params, VectorPatch& vecPatches );
    static void finalizeexchangeGradPhi( Params& params, VectorPatch& vecPatches );
    static void exchangeEnvChi( Params& params, VectorPatch& vecPatches );

    static void exchange_along_all_directions         ( std::vector<Field*> fields, VectorPatch& vecPatches );
    static void finalize_exchange_along_all_directions( std::vector<Field*> fields, VectorPatch& vecPatches );
    static void exchangeComplex                       ( std::vector<Field*> fields, VectorPatch& vecPatches );
    static void finalizeexchangeComplex               ( std::vector<Field*> fields, VectorPatch& vecPatches );
    static void exchange_synchronized_per_direction   ( std::vector<Field*> fields, VectorPatch& vecPatches );

    static void exchange_all_components_along_X          ( std::vector<Field*>& fields, VectorPatch& vecPatches );
    static void finalize_exchange_all_components_along_X ( std::vector<Field*>& fields, VectorPatch& vecPatches );
    static void exchange_all_components_along_Y          ( std::vector<Field*>& fields, VectorPatch& vecPatches );
    static void finalize_exchange_all_components_along_Y ( std::vector<Field*>& fields, VectorPatch& vecPatches );
    static void exchange_all_components_along_Z          ( std::vector<Field*> fields, VectorPatch& vecPatches );
    static void finalize_exchange_all_components_along_Z ( std::vector<Field*> fields, VectorPatch& vecPatches );

    //! Deprecated field functions
    static void exchange_along_X          ( std::vector<Field*> fields, VectorPatch& vecPatches );
    static void finalize_exchange_along_X ( std::vector<Field*> fields, VectorPatch& vecPatches );
    static void exchange_along_Y          ( std::vector<Field*> fields, VectorPatch& vecPatches );
    static void finalize_exchange_along_Y ( std::vector<Field*> fields, VectorPatch& vecPatches );
    static void exchange_along_Z          ( std::vector<Field*> fields, VectorPatch& vecPatches );
    static void finalize_exchange_along_Z ( std::vector<Field*> fields, VectorPatch& vecPatches );

};

#endif
