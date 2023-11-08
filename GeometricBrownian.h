#ifndef GEOMETRICBROWNIAN_H
#define GEOMETRICBROWNIAN_H

#include "Paths.h"
#include "Random.h"

class GeometricBrownian : public Paths
{
    private:
        double m_volatility{1.0};
        double m_returnRate{1.0};
    public:
        GeometricBrownian(PathsConfig Config,double volatility, double returnRate):
            Paths{Config},m_volatility{volatility},m_returnRate{returnRate}
            {
                for(int index = 1; index < m_config.nbStep + 1; ++index)
                {
                    m_values[index] = m_values[index - 1]*(1 + m_returnRate*m_config.timeStep + m_volatility*Random::getNormal(0,m_config.timeStep));
                }
            }
};

#endif // GEOMETRICBROWNIAN_H
