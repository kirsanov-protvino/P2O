{
  c1 = new TCanvas("del_delres_eres"," ",200,10,900,600);

  TGraph* graph_del = new TGraph("del_delres_eres.dat");
  graph_del->SetTitle("");
  graph_del->SetLineColor(2);
  graph_del->SetLineWidth(3);
  graph_del->GetXaxis()->SetTitle("Energy resolution #DeltaE/E");
  graph_del->GetYaxis()->SetTitle("#Delta#delta, degrees");
  graph_del->SetMinimum(0.);
  graph_del->Draw("AC");

  TGraph* graph_del_15 = new TGraph("del_delres_eres_15.dat");
  graph_del_15->SetLineColor(3);
  graph_del_15->SetLineWidth(3);
  graph_del_15->Draw("C SAME");

  TGraph* graph_del_1 = new TGraph("del_delres_eres_1.dat");
  graph_del_1->SetLineColor(4);
  graph_del_1->SetLineWidth(3);
  graph_del_1->Draw("C SAME");

}
