/*****************************************************************************
 * Project: CMS detector at the CERN
 *
 * Package: PhysicsTools/TagAndProbe/RooCMSShapeExp
 *
 *
 * Authors:
 *   Nadia Adam, Princeton - neadam@princeton.edu
 *   Adam Hunt, Princeton  - ahunt@princeton.edu
 *   Kalanand Mishra, Fermilab - kalanand@fnal.gov
 *
 * Description:
 *   Defines a probability density function which has exponential decay
 *   distribution at high mass beyond the pole position (say, Z peak)
 *   but turns over (i.e., error function) at low mass due to threshold
 *   effect. We use this to model the background shape in Z->ll invariant
 *   mass.
 * History:
 *
 *
 *****************************************************************************/

#ifndef ROO_CMS_SHAPEEXP
#define ROO_CMS_SHAPEEXP

#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooAbsReal.h"
#include "TMath.h"
#include "RooMath.h"

class RooCMSShapeExp : public RooAbsPdf {
public:
  RooCMSShapeExp() {};
  RooCMSShapeExp(const char *name, const char *title,
	      RooAbsReal& _x,
	      RooAbsReal& _alpha,
	      RooAbsReal& _beta,
	      RooAbsReal& _gamma,
	      RooAbsReal& _peak,
        RooAbsReal& _p1,
        RooAbsReal& _p2);

  RooCMSShapeExp(const RooCMSShapeExp& other, const char* name);
  inline virtual TObject* clone(const char* newname) const { return new RooCMSShapeExp(*this,newname); }
  inline ~RooCMSShapeExp() {}
  Double_t evaluate() const ;


  ClassDef(RooCMSShapeExp,2);

protected:

  RooRealProxy x ;
  RooRealProxy alpha ;
  RooRealProxy beta ;
  RooRealProxy gamma ;
  RooRealProxy peak ;
  RooRealProxy p1 ;
  RooRealProxy p2 ;

};

#endif
