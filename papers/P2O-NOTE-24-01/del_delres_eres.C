{
  gStyle->SetFrameLineWidth(2);

  auto c1 = new TCanvas("del_delres_eres"," ",200,10,900,600);
  c1->SetGrid();

  TGraph* graph_del = new TGraph("del_delres_eres.dat");
  graph_del->SetTitle("");
  graph_del->SetLineColor(kBlue);
  graph_del->SetLineWidth(3);
  graph_del->GetXaxis()->SetTitle("#DeltaE/E");
  graph_del->GetXaxis()->SetTitleSize(1.2*graph_del->GetXaxis()->GetTitleSize());
  graph_del->GetYaxis()->SetTitle("#Delta#delta [degrees]");
  graph_del->GetYaxis()->SetTitleSize(1.2*graph_del->GetYaxis()->GetTitleSize());  
  graph_del->SetMinimum(0.);
  graph_del->Draw("AC");

  TGraph* graph_del_15 = new TGraph("del_delres_eres_15.dat");
  graph_del_15->SetLineColor(kRed);
  graph_del_15->SetLineWidth(3);
  graph_del_15->Draw("C SAME");

  TGraph* graph_del_1 = new TGraph("del_delres_eres_1.dat");
  graph_del_1->SetLineColor(kGreen);
  graph_del_1->SetLineWidth(3);
  graph_del_1->Draw("C SAME");

  TGraph* graph_del_0 = new TGraph("del_delres_eres_0.dat");
  graph_del_0->SetLineColor(kBlack);
  graph_del_0->SetLineWidth(3);
  graph_del_0->Draw("C SAME");

}
