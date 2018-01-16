using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpDemoLibrary
{
    // This class implements the methods exposed by the DLL's IBaseInterface
    public class ManagedCalculator : IBaseInterface
    {
        public int Add(int iNum1, int iNum2)
        {
            return (iNum1 + iNum2);
        }

        public int Subtract(int iNum1, int iNum2)
        {
            return (iNum1 - iNum2);
        }

        public bool EqualTo(int iNum1, int iNum2)
        {
            return (iNum1 == iNum2);
        }

        public bool GreaterThan(int iNum1, int iNum2)
        {
            return (iNum1 > iNum2);
        }

        public bool LesserThan(int iNum1, int iNum2)
        {
            return (iNum1 < iNum2);
        }

        public int Modulus(int iNum1, int iNum2)
        {
            return (iNum1 % iNum2);
        }

        public int Multiply(int iNum1, int iNum2)
        {
            return (iNum1 * iNum2);
        }
    }
}
