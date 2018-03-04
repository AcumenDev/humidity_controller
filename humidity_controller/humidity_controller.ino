void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

float computeHumidity(float dryT, float wetT)
{
  float vaporPressure = computeVaporPressure(dryT,wetT);
  float saturationPtressure = computeSaturationPressure(dryT);
  return 100*vaporPressure/saturationPressure;
}

float computeVaporPressure(float dryT, float wetT)
{
  const double A = 0.0007947;
  const int p = 1000;
  const double а = 0,00115;
  //TODO
  return 0.0;
}

float computeSaturationPressure(float t)
{
  const double E = 6.1121;
  const double a = 17.5043;
  const double b = 241.2;
  //TODO
  return 1.0;
}
