#ifndef RELOJ_H_
#define RELOJ_H_
#include <iostream>

class Reloj
{
  public:
    Reloj();
    Reloj(int hr, int min);
    void muestra( );
    void setHora(int hr);
    void setMinutos(int min);
    int getHora();
    int getMinutos();
    void operator++();  // incrementa un minuto al reloj
		void operator--();  // decrementa un minuto al reloj
		Reloj operator+(int);  // suma un Reloj con una cantidad de minutos y regresa el nuevo Reloj
		Reloj operator+(Reloj);  // suma un Reloj con otro Reloj y regresa un nuevo Reloj
		Reloj operator-(int);  // a un Reloj le resta una cantidad de minutos y regresa el nuevo Reloj
		Reloj operator-(Reloj); // a un Reloj le resta otro Reloj y regresa el nuevo Reloj
		bool operator>(Reloj);  // regresa true/false si el primer Reloj es > el segundo
		bool operator<(Reloj); // regresa true/false si el primer Reloj es < el segundo
		bool operator==(Reloj); // regresa true/false si ambos relojes son iguales

  private:
    int hora, minu;
};

Reloj::Reloj()
{
hora = 0;
minu = 0;
}

Reloj::Reloj(int hr, int min)
{
hora = hr;
minu = min;
}

void Reloj::muestra()
{
if(hora<10)
  std::cout<<"0"<<hora<<":";
  else
  std::cout<< hora<<":";
  if (minu<10)
  std::cout<<"0"<<minu;
  else
  std::cout<<minu<<std::endl;

}

void Reloj::setHora(int hr)
{
hora = hr;
}

void Reloj::setMinutos(int min)
{
minu = min;
}

int Reloj::getHora()
{
return hora;
}

int Reloj::getMinutos()
{
return minu;
}

void Reloj::operator++(){
    minu++;
    do{
        if(minu>=60){
            hora++;
            minu=minu-60;
            if(hora>=23){
                hora=hora-24;
            }
        }
    }while(minu>59);

}

void Reloj::operator--(){
    if(!hora==0&&!minu==0){
        
        if(minu>0){
            minu--;
            if(minu<=0&&hora>0){
                minu=minu+59;
                hora--;
            }
        }
    }else{
        minu=59;
        hora=23;

    }
}

Reloj Reloj::operator+(int a){
    int h,m;
    m=minu+a;
    h=hora;
    do{
        if(m>=60){
            h++;
            m=m-60;
            if(h>=23){
                h=h-24;
            }
        }
    }while(m>59);
    Reloj nuevo(h,m);
    return nuevo;
}

Reloj Reloj::operator+(Reloj a){
    int h,m;
    m=minu+a.minu;
    h=hora+a.hora;
    do{
        if(m>=60){
            h++;
            m=m-60;
            if(h>=23){
                h=h-24;
            }
        }
    }while(m>59);
    Reloj nuevo(h,m);
    return nuevo;
}

Reloj Reloj::operator-(Reloj a){
    int h,m;
    m=minu-a.minu;
    h=hora-a.hora;

        if(m<0)
            m=m+59;
        if(h<0)
            h=h+23;
            
        
    Reloj nuevo(h,m);
    return nuevo;
}

Reloj Reloj::operator-(int a){
    int h,m;
    m=minu-a;
    h=hora;
    do{
        if(m<=0){
            h--;
            m=m+59;
            if(h<=0){
                h=h-24;
            }
        }
    }while(m<0);
    Reloj nuevo(h,m);
    return nuevo;
}

bool Reloj::operator<(Reloj a){
    
    if(hora<=a.hora){
        if(hora==a.hora){
            if(minu<=a.minu)
                return true;
            else
                return false;
        }else{ 
        return true;
        }
    }
    else{
        return false;
    }
}

bool Reloj::operator>(Reloj a){
    if(hora>=a.hora){
        if(hora==a.hora){
            if(minu>=a.minu)
                return true;
            else
                return false;
        }else{ 
        return true;
        }
    }
    else{
        return false;
    }
}

bool Reloj::operator==(Reloj a){
    if(hora==a.hora&&minu==a.minu)
        return true;
    else
        return false;
}

#endif
