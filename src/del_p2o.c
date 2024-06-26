/* GLoBES -- General LOng Baseline Experiment Simulator
 * (C) 2002 - 2004,  The GLoBES Team
 *
 * https://www.mpi-hd.mpg.de/personalhomes/globes/
 *
 * GLoBES is mainly intended for academic purposes. Proper
 * credit must be given if you use GLoBES or parts of it. Please
 * read the section 'Credit' in the README file.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/***************************************************************************
 *   G L o B E S   -   P H Y S I C S   A N D   A P P L I C A T I O N S     *
 *                                                                         *
 *             24 - 26 January 2007, Heidelberg, Germany                   *
 *                                                                         *
 *   Hands-on session: Simulation of Accelerator neutrino experiments      *
 ***************************************************************************
 *   Part 2: Confidence regions in the th13-delta_CP plane                 *
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include <globes/globes.h>   /* GLoBES library */

/* Output file */
char MYFILE[]="del_p2o.dat";
char AEDLFILE[]="p2o.glb";
/*char MYFILE[]="del_1160_1.dat"; */
/*char AEDLFILE[]="ihep_1160_far_1.glb";*/
/* char AEDLFILE[]="T2K-tutorial.glb"; */
FILE *outfile = NULL;

int main(int argc, char *argv[])
{ 
  /* Initialize libglobes */
  glbInit(argv[0]); 
  glbSelectMinimizer(GLB_MIN_POWELL);

  /* Initialize experiment */
  glbInitExperiment(AEDLFILE, &glb_experiment_list[0], &glb_num_of_exps);

  /* Intitialize output */
  outfile = fopen(MYFILE, "w");
  if (outfile == NULL)
  {
    printf("Error opening output file.\n");
    return -1;
  }

/* Define "true" oscillation parameters (cf. hep-ph/0405172v5) */
/*  
  double theta12 = asin(sqrt(0.3));
  double theta13 = asin(sqrt(0.1))/2.0;
  double theta23 = 45.0 * M_PI/180.0;
  double deltacp = 90.0 * M_PI/180.0;
  double sdm = 7.9e-5;
  double ldm = 2.6e-3;
*/
/*
  double theta12 = asin(sqrt(0.857))/2.0;
  double theta13 = asin(sqrt(0.098))/2.0;
  double theta23 = 45.0 * M_PI/180.0;
  double deltacp = 0.0 * M_PI/180.0;
  double sdm = 7.5e-5;
  double ldm = 2.32e-3;
*/  
//
/*   PDG   2022 */
//
  double theta12 = asin(sqrt(0.307));
  double theta13 = asin(sqrt(0.022));
  double theta23 = asin(sqrt(0.546));
  double deltacp = 1.36 * M_PI;
  double sdm = 7.53e-5;
  double ldm = 2.453e-3;
//
/*   Errors PDG   2022 */
//
  double etheta12 = asin(sqrt(0.013));
  double etheta13 = asin(sqrt(0.0007));
  double etheta23 = asin(sqrt(0.021));
  double edeltacp = 0.2 * M_PI;
  double esdm = 0.18e-5;
  double eldm = 0.033e-3; 
//

  deltacp = 0.5 * M_PI;


/* Define "true" oscillation parameter vector */
  glb_params true_values = glbAllocParams();
  glbDefineParams(true_values, theta12, theta13, theta23, deltacp, sdm, ldm);
  glbSetDensityParams(true_values, 1.0, GLB_ALL);
 
  fprintf(stdout, "Total: %g\n", glbTotalRuleRate(0, 1, GLB_ALL, GLB_WO_EFF, GLB_WO_BG, GLB_WO_COEFF, GLB_SIG));
//  glbTotalRuleRate(0, 1, GLB_ALL, GLB_WO_EFF, GLB_WO_BG, GLB_WO_COEFF, GLB_SIG);

  int ichannel = 0;
  double* rates_ch = glbGetChannelRatePtr(0, ichannel, GLB_PRE);
  int n_bins = glbGetNumberOfBins(0);
  double chrate = 0.;
  for(int i=0; i<n_bins; i++) {
    chrate += rates_ch[i];
  }
  fprintf(stdout, "total channel rate: %g\n", chrate);

  /* Define initial guess for the fit values */ 
  glb_params test_values = glbAllocParams();
  glbDefineParams(test_values, theta12, theta13, theta23, deltacp, sdm, ldm);
  glbSetDensityParams(test_values, 1.0, GLB_ALL);

  /* Define external input (1-sigma errors) on the parameters: 10% error
   * on the solar parameters, 5% on the matter density, all other parameters free.
   * External input is implemented as a prior of the form
   *    (fit_value - central_value)^2 / input_error^2
   */
  glb_params input_errors = glbAllocParams();
  glbDefineParams(input_errors, theta12*0.1, 0, 0, 0, sdm*0.1, 0);
  glbSetDensityParams(input_errors, 0.05, GLB_ALL);
  glbSetInputErrors(input_errors);
  glbSetCentralValues(true_values);

  /* Define projection onto th13 and delta, marginalizing over
   * th23 and dm31. The solar parameters can be kept fixed to speed
   * up the calculation without introducing large errors. */
  glb_projection th13delta_projection = glbAllocProjection();
  glbDefineProjection(th13delta_projection,GLB_FIXED,GLB_FIXED,GLB_FREE,
    GLB_FIXED,GLB_FIXED,GLB_FREE);
  glbSetDensityProjectionFlag(th13delta_projection, GLB_FIXED, GLB_ALL);
  glbSetProjection(th13delta_projection);  
/*
  glb_projection delta_projection = glbAllocProjection();
  glbDefineProjection(delta_projection,GLB_FIXED,GLB_FIXED,GLB_FIXED,
    GLB_FREE,GLB_FIXED,GLB_FIXED);
  glbSetDensityProjectionFlag(delta_projection, GLB_FIXED, GLB_ALL);
  glbSetProjection(delta_projection);  
*/  
  /* Compute simulated data */
  glbSetOscillationParameters(true_values);
  glbSetRates();

  /* Scan the th13-delta plane */
  /*
  double this_th13;
  double th13_lower  = asin(sqrt(0.02))/2.0;
  double th13_upper  = asin(sqrt(0.25))/2.0;
  double th13_steps  = 15;
  */
  double this_delta;
 /* double delta_lower = -M_PI;
    double delta_upper = M_PI; */
  double delta_lower = 0.;
  double delta_upper = 2.*M_PI;
  double delta_steps = 400;
  /*  double delta_steps = 15; */
  double res;
  int ithr=0;
  /*
  for(this_th13=th13_lower; this_th13<=th13_upper; this_th13+=(th13_upper-th13_lower)/th13_steps)
  {
  */
    for(this_delta=delta_lower; this_delta<=delta_upper; this_delta+=(delta_upper-delta_lower)/delta_steps)
    {
      /* Set vector of test=fit values */
      /*      glbSetOscParams(test_values, this_th13, GLB_THETA_13); */
      glbSetOscParams(test_values, this_delta, GLB_DELTA_CP);

      /* Compute chi^2 assuming the normal mass hierarchy in the fit */
      res = glbChiNP(test_values, NULL, GLB_ALL);
      //fprintf(outfile, "%g %g\n", this_delta*180.0/M_PI, res);
      fprintf(outfile, "%g %g\n", this_delta*180.0/M_PI, sqrt(res));

      if(!ithr && this_delta*180.0/M_PI > 90. && res > 1.) {
        fprintf(stdout, "delta measurement error: %g\n", this_delta*180.0/M_PI - 90.);
        ithr = 1;
      }

    }
    /*
    fprintf(outfile, "\n");
  }
*/
  fclose(outfile);
  
  // Control printout:

  fprintf(stdout, "Total: %g\n", glbTotalRuleRate(0, 1, GLB_ALL, GLB_WO_EFF, GLB_WO_BG, GLB_WO_COEFF, GLB_SIG));
//  glbTotalRuleRate(0, 1, GLB_ALL, GLB_WO_EFF, GLB_WO_BG, GLB_WO_COEFF, GLB_SIG);

  ichannel = 0;
  rates_ch = glbGetChannelRatePtr(0, ichannel, GLB_PRE);
  n_bins = glbGetNumberOfBins(0);
  chrate = 0.;
  for(int i=0; i<n_bins; i++) {
    chrate += rates_ch[i];
  }
  fprintf(stdout, "total channel rate: %g\n", chrate);


  /* Destroy parameter and projection vector(s) */
  glbFreeParams(true_values);
  glbFreeParams(test_values);
  glbFreeParams(input_errors);
  glbFreeProjection(th13delta_projection);

  return 0;
}

