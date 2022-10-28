from setuptools import setup, find_packages

setup(
    name="pyArborX",
    version="0.1",
    packages=find_packages(include=["pyArborX", "pyArborX.*"]),
    include_package_data=True
)
