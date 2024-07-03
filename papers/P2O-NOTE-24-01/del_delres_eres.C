{
  c1 = new TCanvas("del_delres_eres"," ",200,10,900,600);

  TGraph* graph_del = new TGraph("del_delres_eres.dat");
  graph_del->Draw("ac");
}
