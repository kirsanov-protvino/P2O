{
  c1 = new TCanvas("del_signif_eres"," ",200,10,900,600);

  TGraph* graph_del = new TGraph("del_signif_eres.dat");
  graph_del->Draw();
}
