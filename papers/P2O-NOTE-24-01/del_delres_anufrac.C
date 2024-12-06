{
  gStyle->SetTextFont(1);
  //gStyle->SetLineWidth(3);
  gStyle->SetFrameLineWidth(2);

  auto c1 = new TCanvas("del_delres_anufrac"," ",200,10,900,600);
  c1->SetGrid();

  TGraph* graph_del = new TGraph("del_delres_anufrac.dat");
  graph_del->SetTitle("");
  //graph_del->SetLineColor(kBlue);
  graph_del->SetLineWidth(3);
  graph_del->GetXaxis()->SetTitle("P(#bar #nu_{#mu})");
  graph_del->GetXaxis()->SetTitleSize(1.15*graph_del->GetXaxis()->GetTitleSize());
  graph_del->GetYaxis()->SetTitle("#Delta#delta [degrees]");
  graph_del->GetYaxis()->SetTitleSize(1.2*graph_del->GetYaxis()->GetTitleSize());
  graph_del->SetMinimum(0.);
  graph_del->Draw("AC");
}
