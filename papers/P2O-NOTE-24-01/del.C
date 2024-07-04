{
  c1 = new TCanvas("del"," ",200,10,900,600);

  TGraph* graph_del = new TGraph("del_05.dat");
  graph_del->Draw();
  TGraph* graph_del1 = new TGraph("del_15.dat");
  graph_del1->Draw("SAME");
}
