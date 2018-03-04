void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

float computeHumidity(float dryT, float wetT)
{
  float vaporPressure = computeVaporPressure(dryT,wetT);
  float saturationPressure = computeSaturationPressure(dryT);
  return 100*vaporPressure/saturationPressure;
}

float computeVaporPressure(float dryT, float wetT)
{
  const double A = 0.0007947;
  const int p = 1000;
  const double a = 0.00115;
  float saturationPressureWet = computeSaturationPressure(wetT);
  float vaporPressure = saturationPressureWet - A*p*(dryT-wetT)*(1+a*wetT);
  return vaporPressure;
}

float computeSaturationPressure(float t)
{
  const double E = 6.1121;
  const double a = 17.5043;
  const double b = 241.2;
  float pressure = E * exp(abs(a*t/(b+t)));
  return pressure;
}
