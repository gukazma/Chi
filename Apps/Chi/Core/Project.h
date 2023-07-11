/*
 * @Author       : gukazma && gukazma@proton.me
 * @Date         : 2023-07-10 22:54:06
 * @FilePath     : \Chi\Apps\Chi\Core\Project.h
 * @Description  :
 * MIT License
 *
 * Copyright (c) 2023 gukazma
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files, to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 *
 */
#pragma once
#include <QObject>
#include <boost/filesystem/path.hpp>
#include <boost/property_tree/ptree.hpp>
#include <string>
class Project
{
public:
    Project()  = default;
    ~Project() = default;

    void create(const boost::filesystem::path& path_, std::string name_);

    void open(const boost::filesystem::path& path_);
    void save();
    void update();

    std::string                 projectName;
    boost::filesystem::path     projectDir;
    boost::filesystem::path     imageDir;
    boost::filesystem::path     matchesDir;
    boost::property_tree::ptree m_projectPtree;
};

extern Project g_project;
