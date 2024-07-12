{
  gROOT->ForceStyle();

  gStyle->SetOptStat(1111111);

  // Defaults for LabelFont, LabelSize, LabelOffset
  //               42         0.035        0.005
  // Defaults for TitleFont, TitleSize, TitleOffset
  //               42         0.035        0.005
  gStyle->SetLabelOffset(0.007, "X");
  gStyle->SetTitleOffset(1.1, "X");
  gStyle->SetLabelOffset(0.007, "Y");
  gStyle->SetTitleOffset(1.1, "Y");

  gStyle->SetHistLineWidth(2);
  gStyle->SetHistLineColor(4);
  gStyle->SetMarkerStyle(8);
  gStyle->SetMarkerColor(4);
  gStyle->SetMarkerSize(1.5);
}
