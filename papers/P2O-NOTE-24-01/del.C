{
  auto c1 = new TCanvas("del"," ",200,10,900,600);
  c1->SetGrid();

  int BW = 0;

  TGraph* graph_del = new TGraph("del_05.dat");
  graph_del->SetTitle("");
  graph_del->SetLineWidth(3);
  if(!BW) graph_del->SetLineColor(kBlue);
  if(BW) graph_del->SetLineStyle(0);
  graph_del->GetXaxis()->SetTitle("Hypothetical #delta");
  graph_del->GetYaxis()->SetTitle("#sqrt{#chi^{2}}");
  graph_del->GetXaxis()->SetLimits(0., 360.);
  graph_del->Draw("AC");

  TGraph* graph_del_15 = new TGraph("del_15.dat");
  graph_del_15->SetLineWidth(3);
  if(!BW) graph_del_15->SetLineColor(kRed);
  if(BW) graph_del_15->SetLineStyle(2);
  graph_del_15->Draw("C SAME");

  TGraph* graph_del_1 = new TGraph("del_1.dat");
  graph_del_1->SetLineWidth(3);
  if(!BW) graph_del_1->SetLineColor(kGreen);
  if(BW) graph_del_1->SetLineStyle(9);
  graph_del_1->Draw("C SAME");

  TGraph* graph_del_0 = new TGraph("del_0.dat");
  graph_del_0->SetLineWidth(3);
  //graph_del_0->SetLineColor(kGreen);
  if(BW) graph_del_0->SetLineStyle(10);
  graph_del_0->Draw("C SAME");
}
