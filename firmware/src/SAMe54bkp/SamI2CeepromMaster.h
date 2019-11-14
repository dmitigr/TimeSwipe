/*
This Source Code Form is subject to the terms of the GNU General Public License v3.0.
If a copy of the GPL was not distributed with this
file, You can obtain one at https://www.gnu.org/licenses/gpl-3.0.html
Copyright (c) 2019 Panda Team
*/


//#ifndef SAMI2CEEPROMMASTER_H
//#define SAMI2CEEPROMMASTER_H
#pragma once

#include "SamSercom.h"
class CSamI2CeepromMaster : public CSamSercom
{
public:
    enum    FSM{

        halted,

        //writing to the mem:
        start,
        addrHb,
        addrLb,
        write,

        //reading:
        read,

        //errors:
        errTransfer

        //errLine,
        //errTimeout
    };

protected:
    FSM    m_MState=FSM::halted;
    void IRQhandler();
    bool m_bIRQmode=false;

    int  m_nDevAddr=0x50;           //device address
    int  m_nMemAddr=0;              //memory address
    int  m_nCurMemAddr=0;           //additional variable for processing pages
    int  m_nPageBytesLeft;
   // int  m_nCurPageEndAddr;
    int  m_nReadDataCountLim=4096;  //a limit for the data to read out
    bool m_IOdir=false;             //false -read, true write
    static const int m_nPageSize=16;

    unsigned long m_OpTmt_mS=500;

    std::shared_ptr<CSamCLK> m_pCLK;
    CFIFO *m_pBuf=nullptr; //one single buf for R\W?

    virtual void OnIRQ0();
    virtual void OnIRQ1();
    virtual void OnIRQ2();
    virtual void OnIRQ3();

    //helpers:
    void SetWriteProtection(bool how);
    void StartTranfer(bool how);
    void rewindMemBuf(); //{m_nMemCurInd=0;}
    int readB();
    int writeB(int val);

    //09.11.2019:
    bool write_next_page(); //since only 1 page can be written at once


public:
    CSamI2CeepromMaster();

    inline bool    isIRQmode(){return m_bIRQmode;}
    inline void    SetDeviceAddr(int nDevAddr){m_nDevAddr=nDevAddr; }
    inline void    SetDataAddrAndCountLim(int nDataAddr, int nCountLim=4096){m_nMemAddr=nDataAddr;  m_nReadDataCountLim=nCountLim;}
    void EnableIRQs(bool how);

    //serial:
    virtual bool send(CFIFO &msg); //{ return false;}
    virtual bool receive(CFIFO &msg); //{return false;}
    virtual bool send(typeSChar ch){return false;}
    virtual bool receive(typeSChar &ch){return false;}
};

//#endif // SAMI2CEEPROMMASTER_H