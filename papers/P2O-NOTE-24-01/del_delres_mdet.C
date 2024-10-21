{
  auto c1 = new TCanvas("del_delres_mdet"," ",200,10,900,600);
  c1->SetGrid();

  TGraph* graph_del = new TGraph("del_delres_mdet1.dat");
  graph_del->SetTitle("#delta CP resolution for energy resolutions 0.3 (nominal) and 0.05");
  graph_del->SetLineColor(kBlue);
  graph_del->SetLineWidth(3);
  graph_del->GetXaxis()->SetTitle("Detector mass, mt");
  graph_del->GetYaxis()->SetTitle("#Delta#delta, degrees");
  graph_del->SetMinimum(0.);
  graph_del->Draw("AC");

  TGraph* graph_del_1 = new TGraph("del_delres_mdet2.dat");
  graph_del_1->SetLineColor(kBlue);
  graph_del_1->SetLineWidth(3);
  graph_del_1->Draw("C SAME");
}
