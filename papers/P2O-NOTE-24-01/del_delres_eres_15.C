{
  c1 = new TCanvas("del_delres_eres_15"," ",200,10,900,600);

  TGraph* graph_del = new TGraph("del_delres_eres_15.dat");
  graph_del->Draw("ac");
}
