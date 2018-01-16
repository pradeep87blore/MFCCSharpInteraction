using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpDemoLibrary
{
    // This interface lists the methods that shall be exposed by the C# DLL
    public interface IBaseInterface
    {
        int Add(int iNum1, int iNum2);

        int Subtract(int iNum1, int iNum2);

        bool GreaterThan(int iNum1, int iNum2);

        bool LesserThan(int iNum1, int iNum2);

        bool EqualTo(int iNum1, int iNum2);

        int Modulus(int iNum1, int iNum2);

        int Multiply(int iNum1, int iNum2);
    }
}
