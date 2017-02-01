/**
* @file
*
* This file defines the class stGHTree.
* $Author: seraphim $
*
* @author Enzo Seraphim (seraphim@unifei.edu.br)
*/

#ifndef __STGNUPLOT_H
#define __STGNUPLOT_H

class stGnuplot {
   public:

 	  enum tOutputPlot{
	     plotWindows,
	     plotX11,
	     plotEps,
        plotPs
     };

      stGnuplot() {
         fontsize = -1;
         legend = true;
         xlabel = NULL;
         title = NULL;
      };

      virtual ~stGnuplot();

      void SetFontSize(int size) { fontsize = size; };

      void SetTitle(const char * str);

      void SetXLabel(const char * label);

      void SetLegend(bool leg = true) { legend = leg; };

      int GetFontSize() { return fontsize; };

      char * GetTitle() { return title; };

      char * GetXLabel() { return xlabel; };

      bool GetLegend() { return legend; };

      virtual void SaveTo(char * filename, tOutputPlot type = plotWindows) = 0;

   private:
      char * xlabel;
      char * title;
      int fontsize;
      bool legend;
};

#endif // __STGNUPLOT_H
