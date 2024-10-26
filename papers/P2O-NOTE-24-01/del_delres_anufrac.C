{
  auto c1 = new TCanvas("del_delres_anufrac"," ",200,10,900,600);
  c1->SetGrid();

  TGraph* graph_del = new TGraph("del_delres_anufrac.dat");
  graph_del->SetTitle("");
  //graph_del->SetLineColor(kBlue);
  graph_del->SetLineWidth(3);
  graph_del->GetXaxis()->SetTitle("Fraction of antineutrino in exposition");
  graph_del->GetYaxis()->SetTitle("#Delta#delta, degrees");
  graph_del->SetMinimum(0.);
  graph_del->Draw("AC");
}
