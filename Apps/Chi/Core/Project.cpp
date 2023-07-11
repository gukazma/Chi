#include "Project.h"
#include <boost/property_tree/xml_parser.hpp>

Project g_project;

void Project::create(const boost::filesystem::path& path_, std::string name_)
{
    projectDir  = path_;
    projectName = name_;
    update();
    save();
}

void Project::open(const boost::filesystem::path& path_)
{
    boost::property_tree::read_xml(path_.generic_string(), m_projectPtree);
}

void Project::save()
{
    boost::filesystem::path savepath = projectDir / projectName;
    savepath.replace_extension(".chi");
    boost::property_tree::write_xml(savepath.generic_string(), m_projectPtree);
}

void Project::update()
{
    m_projectPtree.clear();
    m_projectPtree.put("Project.Name", projectName);
    m_projectPtree.put("Project.Path", projectDir);
    m_projectPtree.put("Project.SFM.ImageDir", imageDir);
    m_projectPtree.put("Project.SFM.MatchDir", matchesDir);
}
